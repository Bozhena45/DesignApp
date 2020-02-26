#include "bbdd.h"
#include <QSqlRecord>

Bbdd::~Bbdd()
{
    if (m_db.isOpen())
    {
        m_db.close();
    } // end if
}

bool Bbdd::insert()
{


    QSqlQuery query(m_db);

     /// 1)INSERTAR EN LA BBDD UN USUARIO
    query.prepare("INSERT INTO usuario (nombre,email,password) VALUES (:nombre,:email,:password)");
    query.bindValue(":nombre", "Paquito");
    query.bindValue(":email", "Paquito@gmail.com");
    query.bindValue(":password", "44");

     /// 2)INSERTAR EN LA BBDD TIPO DE ESTILO
    query.prepare("INSERT INTO style (tipo) VALUES (:tipo)");
    query.bindValue(":tipo", "roquero");

   /// 3)INSERTAR EN LA BBDD TIPO DE PHOTO
        query.prepare("INSERT INTO imagenes (uurl,siize,liike) VALUES (:uurl,:siize,:liike)");
        query.bindValue(":uurl", "afasf");
        query.bindValue(":siize", "0.5");
        query.bindValue(":liike", "20");

    bool result = query.exec();
    qDebug() << query.lastError().text();
    return result;


}

/*bool Bbdd::load(std::string nombre)
{
     QSqlQuery query(m_db);
     /// 1)Hacer una SELECT en la bbdd para saber si existe el usuario o no
         query.prepare("SELECT * from usuario where nombre = :nombre ");

         query.bindValue(":nombre",QString::fromStdString(nombre));
         query.exec();





}*/

Bbdd::Bbdd()
{
    if (!QSqlDatabase::contains( "MyDb"))
    {
        m_db = QSqlDatabase::addDatabase("QPSQL", "MyDb");
    }
    else
    {
        m_db = QSqlDatabase::database("MyDb");
    } // end if
    m_db.setHostName("localhost");
    m_db.setPort(5432);
    m_db.setUserName("postgres");
    m_db.setPassword("");

}

void Bbdd::close()
{
    m_db.close();
}

bool Bbdd::init()
{
    bool result = 0;

    m_db.close();
    m_db.setDatabaseName("template1");

    bool ok = m_db.open();

    if (ok)
    {

        qDebug() << "La bbdd se está borrando...";
        QSqlQuery q0("DROP DATABASE IF EXISTS app_doctest", m_db);
        if (q0.lastError().type() == QSqlError::NoError)
        {
            qDebug() << "La bbdd se está creando...";
            QSqlQuery q1("CREATE DATABASE app_doctest", m_db);
            if (q1.lastError().type() == QSqlError::NoError)
            {
                m_db.close();
                m_db.setDatabaseName("app_doctest");
                m_db.open();

                QSqlQuery q("CREATE EXTENSION pgcrypto", m_db);

                /// Crea estructura en la base de datos
                QString sql1 {"CREATE TABLE usuario ( \
                    idUsuario  SERIAL, \
                    nombre   varchar(40), \
                    email   varchar(40), \
                    password   varchar(40), \
                            PRIMARY KEY(idUsuario) \
                )"};


               QString sql2 {"CREATE TABLE style ( \
               idtipo  SERIAL, \
               tipo   varchar(40), \
               PRIMARY KEY(idtipo) \
                                )"};

             QString sql3 {"CREATE TABLE imagenes ( \
                idphoto  SERIAL, \
                uurl   varchar(40), \
                siize   varchar(40), \
                liike   varchar(40), \
                PRIMARY KEY(idphoto) \
                                        )"};

                qDebug() << "Iniciando bbdd...";

                QSqlQuery q2(sql1, m_db);
                QSqlQuery q3(sql2, m_db);
                QSqlQuery q4(sql3, m_db);

                if ((q2.lastError().type() == QSqlError::NoError)|| (q3.lastError().type() == QSqlError::NoError) )
                {
                    result = true;
                } // end if
            }
            else
            {
                qDebug() << "BB:" << m_db.lastError().text();
            } // end if

        }
        else
        {
            qDebug() << "AA:" << m_db.lastError().text();
        } // end if

    } // end if

    return result;
}

QSqlError Bbdd::lastError()
{
    return m_db.lastError();
}


























