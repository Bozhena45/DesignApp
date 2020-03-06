#include "server.h"
#include <QFile>
#include <QDebug>
Server::Server()
{

}

void Server::processLine(std::string line)
{
    std::string nuevaLinea = line.substr(0,line.rfind("\n"));

    std::string clave = nuevaLinea.substr(0,nuevaLinea.rfind("="));
    std::string valor = nuevaLinea.substr(nuevaLinea.rfind("=") + 1,nuevaLinea.size());

    m_properties[clave] = valor;

}

void Server::ReadFile()
{
    QString nombreArchivo = "../baseDatos.conf";

    if (QFile::exists(nombreArchivo))
    {
        QFile file(nombreArchivo);

        if(file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            while (!file.atEnd()) {
                std::string line = QString(file.readLine()).toUtf8().constData();
                processLine(line);

            }
        }
    }
    else {
        qDebug()<<"error";
        exit(0);
    }
}


void Server::loadProperties()
{
    ReadFile();

    m_hostName = QString::fromUtf8(m_properties["hostname"].c_str());
    m_databaseName = QString::fromUtf8(m_properties["databaseName"].c_str());
    m_port = std::stoi(m_properties["port"]);
    m_userName = QString::fromUtf8(m_properties["userName"].c_str());
    m_password = QString::fromUtf8(m_properties["password"].c_str());
}

bool Server::existe(const json& json, const std::string& key)
{
    return json.find(key) != json.end();
}

bool Server::connectBBDD()
{
    loadProperties();
    QSqlDatabase bbdd = QSqlDatabase::addDatabase("QPSQL");
    bbdd.setHostName(m_hostName);
    bbdd.setDatabaseName(m_databaseName);
    bbdd.setPort(m_port);
    bbdd.setUserName(m_userName);
    bbdd.setPassword(m_password);


    bool ok = bbdd.open();
    return ok;
}

int Server::StartServer(int puerto)
{

    bool ok = connectBBDD();
    if (ok){
        qDebug() << "conecta a la base de datos";
    }

    ix::WebSocketServer server(puerto, "0.0.0.0");

    ix::SocketTLSOptions tlsOptions;

    tlsOptions.tls = true;
    tlsOptions.certFile = "./cert/localhost/archivoSalida.crt";
    tlsOptions.keyFile = "./cert/localhost/serverSSL.key";
    tlsOptions.caFile = "NONE";

    if(tlsOptions.isValid()){
        qDebug() << "SSL vaild" ;
    }
    //server.setTLSOptions(tlsOptions);

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
                                    Photo photo("",0,"123",s.getID(),receivedObject["idUser"]);
                                    std::string b64 = receivedObject["base64"];
                                    photo.saveImage(QString::fromUtf8(b64.c_str()));
                                    //photo.createPhoto();
                                    //json respuesta = photo.toJSON();
                                    //respuesta["action"] = "subirFoto";
                                    //webSocket->send(respuesta.dump());

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

                                if (action == "listaComentarios")
                                {

                                    json respuesta;
                                    respuesta["action"] = "listacomentarios";

                                    std::list<Comments> comen = Comments::find(receivedObject["idPhoto"]);
                                    unsigned long contador = 0;
                                    for(Comments coment : comen)
                                    {
                                        json comentario = coment.toJSON();
                                        respuesta["lista"][contador] = comentario;
                                        contador ++;
                                    }
                                    webSocket->send(respuesta.dump());

                                } // end if

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


