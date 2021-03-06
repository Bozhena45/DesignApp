#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QTranslator>
#include <QDebug>
#include <QCoreApplication>
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"
#include "user.h"
#include "photo.h"
#include "style.h"
#include "comments.h"
#include "json.hpp"

using json = nlohmann::json;
/**
 * @brief La clase Servidor
 *
 * Esta clase sirve para poder encender el Servidor y a partir de unos métodos poder
 * conectarlo con la base de datos y hacer los JSON correspondientes
 *
 */
class Server
{
public:
    Server();
    /**
     * @brief El método StartServer
     *
     * Sirve para poder iniciar el Servidor a partir del puerto que le pasas
     * @param puerto
     * @return
     */
    int StartServer(int puerto);
private:
    /**
     * @brief El método connectBBDD
     *
     * Sirve para conectar la base de datos.
     * Se generan los mensajes JSON. Para conectarnos utilizamos el action, a partir de eso se envían y reciben mensajes JSON
     * @return
     */
    bool connectBBDD();
    /**
     * @brief El método existe(si existe o no el JSON)
     * @param json
     * @param key
     * @return devuelve el json
     */
    bool existe(const json& json, const std::string& key);

    void ReadFile();
    void processLine(std::string line);
    std::map<std::string,std::string> m_properties;
    void loadProperties();

    QString m_hostName;
    QString m_databaseName;
    int m_port;
    QString m_userName;
    QString m_password;
};

#endif // SERVER_H
