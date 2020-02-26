#include "user.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>
#include <string>

User::User(std::string nombre,std::string email,std::string password)
{

    this->m_nombre = nombre;
    this->m_email = email;
    this->m_password = password;

}

///2)Crear usuario:
/// 2.1) Hacemos la query del insert(para añadir un nuevo usuario a la bbdd)
/// 2.2) Lo pasamos a JSON
bool User::createUser()
{

    QSqlQuery query;
    query.prepare("INSERT into usuario (name,email,password) values (:nombre,:email,crypt(:passw,gen_salt('bf')))");


    query.bindValue(":nombre", QString::fromStdString(m_nombre));
    query.bindValue(":email", QString::fromStdString(m_email));
    query.bindValue(":passw", QString::fromStdString(m_password));
    query.exec();
    return  true;

}

json User::toJSON()
{
    json usuario;

    usuario["id"] = m_id;
    usuario["nombre"] = m_nombre;
    usuario["email"] = m_email;
    usuario["password"] = m_password;
    return usuario;
}


///3)Buscar usuarios en la bbdd:
/// 3.1)Creamos el metodo load al que le pasamos los parámetros necesarios
/// 3.2)Hacemos la select para buscar el usuario en la bbdd apartir de los parámetros
/// 3.3)Pasamos todas los valores en string para poder luego coger los datos y devolver el usuario pedido

User User::load(std::string usuario,std::string contrasenya)
{

    User u("","","");
    bool contrasenyaCorrecta = false;

    QSqlQuery queryPassword;
    queryPassword.prepare("Select (password = crypt(:password, password)) as pwd_match from usuario where email = :email ");
    queryPassword.bindValue(":password",QString::fromStdString(contrasenya));
    queryPassword.bindValue(":email",QString::fromStdString(usuario));
    queryPassword.exec();

    QSqlRecord rec2 = queryPassword.record();
    if (queryPassword.next())
    {
        contrasenyaCorrecta = QVariant(queryPassword.value("pwd_match")).toBool();
    }

    qDebug() << contrasenyaCorrecta;

    if (contrasenyaCorrecta)
    {
        QSqlQuery query;
        query.prepare("SELECT * from usuario where email = :usuario");
        query.bindValue(":usuario",QString::fromStdString(usuario));
        query.exec();

        QSqlRecord rec = query.record();
        while(query.next())
        {
            QString name = query.value("name").toString();
            QString email = query.value("email").toString();
            QString password = query.value("password").toString();

            User usuario(name.toUtf8().constData(),email.toUtf8().constData(),password.toUtf8().constData());
            usuario.setId(query.value("id_user").toInt());
            return usuario;
        }
    }


    return u;

}

User User::loadN(std::string name)
{

    User u("","","");

    QSqlQuery query;
    query.prepare("SELECT * from usuario where name = :nombre");
    query.bindValue(":nombre",QString::fromStdString(name));
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
    {
        QString name = query.value("name").toString();
        QString email = query.value("email").toString();
        QString password = query.value("password").toString();

        User usuario(name.toUtf8().constData(),email.toUtf8().constData(),password.toUtf8().constData());
        usuario.setId(query.value("id_user").toInt());
        return usuario;
    }

    return u;

}

void User::setId(int id)
{
    this->m_id = id;

}












