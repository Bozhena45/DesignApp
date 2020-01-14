#include "user.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

User::User(std::string nombre,std::string email,std::string password)
{
    this->m_nombre = nombre;
    this->m_email = email;
    this->m_password = password;

}
///1) Listar usuarios:
json User::userList(json& mensaje)
{

    json persona1;
    json persona2;

    persona1["name"] = "Carlos";
    persona1["e-mail"] = "carlos@gmail.com";
    persona1["password"] ="123456" ;

    persona2["name"] = "Maria";
    persona2["e-mail"] = "maria@gmail.com";
    persona2["password"] ="678910" ;

    json respuesta;

    respuesta["id"] = mensaje["id"];
    respuesta["lista"]["1"] = persona1;
    respuesta["lista"]["2"] = persona2;
    return respuesta;

}
///2)Crear usuario:
void User::createUser()
{

    QSqlQuery query;
    query.prepare("INSERT into usuario (name,email,password) values (:nombre,:email,:passw)");


    query.bindValue(":nombre", QString::fromStdString(m_nombre));
    query.bindValue(":email", QString::fromStdString(m_email));
    query.bindValue(":passw", QString::fromStdString(m_password));
    query.exec();


}

json User::toJSON()
{
    json usuario;

    usuario["nombre"] = m_nombre;
    usuario["email"] = m_email;
    usuario["password"] = m_password;
    return usuario;
}













