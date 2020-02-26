#include "server.h"

Server::Server()
{

}

bool Server::existe(const json& json, const std::string& key)
{
    return json.find(key) != json.end();
}

bool Server::connectBBDD()
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

int Server::StartServer(int puerto)
{

    connectBBDD();

    ix::WebSocketServer server(puerto, "0.0.0.0");

    ix::SocketTLSOptions tlsOptions;

    tlsOptions.tls = true;
    tlsOptions.certFile = "/home/usuario/cert/localhost/archivoSalida.crt";
    tlsOptions.keyFile = "/home/usuario/cert/localhost/serverSSL.key";
    tlsOptions.caFile = "NONE";


    server.setTLSOptions(tlsOptions);

    server.setOnConnectionCallback(
        [&server, this](std::shared_ptr<ix::WebSocket> webSocket,
                  std::shared_ptr<ix::ConnectionState> connectionState)
        {
            webSocket->setOnMessageCallback(
                [webSocket, connectionState, &server, this](const ix::WebSocketMessagePtr msg)
                {
                    if (msg->type == ix::WebSocketMessageType::Open)
                    {
                        //std::cout << "New connection" << std::endl;
                        qDebug() << QObject::tr("New connection");
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
                            if (this->existe(receivedObject,"action"))
                            {

                                std::string action = receivedObject["action"];


                                ///CREAR USUARIO
                                ///Utilizamos la acción crearUsuario que es la que tenemos en nuestro javascript
                                ///Cogemos los parámetros necesarios para poder crear nuestro usuario
                                ///Y por último nos devolverá la respuesta pedida por el cliente
                                if (action == "crearUsuario")
                                {
                                    User usuario(receivedObject["nombre"],receivedObject["correoElectronico"],receivedObject["contrasenya"]);
                                    usuario.createUser();
                                    json respuesta = usuario.toJSON();
                                    respuesta["action"] = "registrar";
                                    webSocket->send(respuesta.dump());
                                    qDebug() << QObject::tr("registered user");

                                } // end if

                                if (action == "subirFoto")
                                {

                                    Style s;
                                    s.Load(receivedObject["estilo"]);
                                    Photo photo(receivedObject["imagen"],0,"123",s.getID(),receivedObject["idUser"]);
                                    photo.createPhoto();
                                    json respuesta = photo.toJSON();
                                    respuesta["action"] = "subirFoto";
                                    webSocket->send(respuesta.dump());

                                } //end


                                ///HACER EL LOGIN
                                ///Utilizamos la acción entrar que es la que tenemos en nuestro javascript
                                ///Cogemos los parámetros necesarios para poder entrar con nuestro usuario
                                ///Y por último nos devolverá la respuesta pedida por el cliente
                                if (action == "entrar")
                                {
                                    std::string email = receivedObject["email"];
                                    std::string pass = receivedObject["contrasenya"];

                                    User user = User::load(email,pass);
                                    json respuesta = user.toJSON();
                                    respuesta["action"] = "login";
                                    webSocket->send(respuesta.dump());

                                } // end if

                                if (action == "buscar")
                                {
                                    std::string name = receivedObject["Buscar"];

                                    User user = User::loadN(name);
                                    json respuesta = user.toJSON();
                                    respuesta["action"] = "searchUser";
                                    webSocket->send(respuesta.dump());

                                } // end if

                                if (action == "like")
                                {


                                } //end if

                                if (action == "nuevoComentario")
                                {

                                    Comments comentario(receivedObject["texto"],receivedObject["idUser"],receivedObject["idPhoto"]);
                                    comentario.CreateComment();
                                    json respuesta = comentario.toJSON();
                                    respuesta["action"] = "nuevoComent";
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

void Server::StopServer()
{

}
