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
#include "json.hpp"

using json = nlohmann::json;
/**
 * @brief La clase Servidor
 *
 * Esta clase sirve para poder encender el Servidor y a partir de unos métodos por
 * conectarlo con la bbdd y hacer los JSON correspondientes
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
    void StopServer();
private:
    /**
     * @brief El método connectBBDD
     *
     * Sirve para conectar la bbdd. Dentro de este método la bbdd se conecta con el servidor
     * y además se generan los mensajes JSON que están conectados con las funciones de las funciones de
     * la aplicación
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
};

#endif // SERVER_H
