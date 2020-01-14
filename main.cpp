#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"
#include "user.h"
#include "photo.h"

#include "json.hpp"



using json = nlohmann::json;

bool connectBBDD()
{
  QSqlDatabase bbdd = QSqlDatabase::addDatabase("QPSQL");
  bbdd.setHostName("localhost");
  bbdd.setDatabaseName("DesignApp");
  bbdd.setPort(5432);
  bbdd.setUserName("postgres");
  bbdd.setPassword("");


  bool ok = bbdd.open();
  return ok;
}

bool existe(const json& json, const std::string& key)
{
    return json.find(key) != json.end();
}

int main()
{
    connectBBDD();

    ix::WebSocketServer server(9990, "0.0.0.0");

    server.setOnConnectionCallback(
        [&server](std::shared_ptr<ix::WebSocket> webSocket,
                  std::shared_ptr<ix::ConnectionState> connectionState)
        {
            webSocket->setOnMessageCallback(
                [webSocket, connectionState, &server](const ix::WebSocketMessagePtr msg)
                {
                    if (msg->type == ix::WebSocketMessageType::Open)
                    {
                        std::cout << "New connection" << std::endl;
                        ///Tipos de mensaje;
                        ///  1) Mensaje que no espera respuesta.
                        ///  2) Mensaje que sea una respuesta a una petición previa.
                        ///  3) Mensaje que espera una respuesta.


                        json jsonMessage = {
                            {"type","1"},
                            {"message","Hola"}
                        };


                        std::string messageToSend = jsonMessage.dump();
                        //webSocket->send(messageToSend);


                    }
                    else if (msg->type == ix::WebSocketMessageType::Close)
                    {
                        std::cout << "Bye bye connection" << std::endl;
                    }
                    else if (msg->type == ix::WebSocketMessageType::Message)
                    {
                        if (!msg->binary)
                        {
                            /// Text format
                            std::cout  << msg->str << std::endl;
                        }

                        /// 1) Parsear
                        auto receivedObject = json::parse(msg->str);

                        /// 2) JSON válido?
                        if(receivedObject.is_discarded())
                        {
                            std::cout << "Error" <<std::endl;
                        }
                        else
                        {
                            /// 3) Existe action?
                            if (existe(receivedObject,"action"))
                            {

                                std::string action = receivedObject["action"];

                                if (action == "listaUsuarios")
                                {
                                    json respuesta = User::userList(receivedObject);
                                    webSocket->send(respuesta.dump());
                                } // end if

                                if (action == "listaFotos")
                                {
                                    json respuesta = Photo::photoList(receivedObject);
                                    webSocket->send(respuesta.dump());

                                } // end if

                                if (action == "crearUsuario")
                                {
                                    //json respuesta = User::createUser(receivedObject["nombre"],receivedObject["correoElectronico"],receivedObject["contrasenya"], receivedObject["id"]);
                                    //webSocket->send(respuesta.dump());

                                } // end if

                                if (action == "fotosEliminadas")
                                {
                                    json respuesta = Photo::deletePhoto(receivedObject);
                                    webSocket->send(respuesta.dump());

                                } //end if

                            } // end if

                        } // end if

                    }
                    else if (msg->type == ix::WebSocketMessageType::Error){
                        std::cout << "Error:" <<msg->errorInfo.reason <<std::endl;
                    }
                }
            );
        }
    );



    auto res = server.listen();
    if (!res.first)
    {
        // Error handling
        return 1;
    }

    server.start();
    server.wait();
    server.stop();

    return 0;

}
