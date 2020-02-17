#include "bbdd.h"


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


    bool result = query.exec();
    qDebug() << query.lastError().text();
    return result;





}

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

        qDebug() << "Borrando...";
        QSqlQuery q0("DROP DATABASE IF EXISTS app_doctest", m_db);
        if (q0.lastError().type() == QSqlError::NoError)
        {
            qDebug() << "Creando...";
            QSqlQuery q1("CREATE DATABASE app_doctest", m_db);
            if (q1.lastError().type() == QSqlError::NoError)
            {
                m_db.close();
                m_db.setDatabaseName("app_doctest");
                m_db.open();

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
                qDebug() << "Iniciando...";
                QSqlQuery q3(sql1, m_db);
                QSqlQuery q2(sql2, m_db);
                if (q2.lastError().type() == QSqlError::NoError)
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


























