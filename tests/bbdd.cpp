#include "bbdd.h"



Bbdd::~Bbdd()
{
    if (m_database.isOpen())
    {
        m_database.close();
    } // end if
}

bool Bbdd::insert()
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO usuario VALUES (:nombre_tabla)");
    query.bindValue(":nombre_tabla", "prueba");
    bool result = query.exec();
qDebug() << query.lastError().text();
    return result;
}

Bbdd::Bbdd()
{
    if (!QSqlDatabase::contains( "MyDb"))
    {
        m_database = QSqlDatabase::addDatabase("QPSQL", "MyDb");
    }
    else
    {
        m_database = QSqlDatabase::database("MyDb");
    } // end if
    m_database.setHostName("localhost");
    m_database.setPort(5432);
    m_database.setUserName("postgres");
    m_database.setPassword("");

}

void Bbdd::close()
{
    m_database.close();
}

bool Bbdd::init()
{
    bool result = 0;

    m_database.close();
    m_database.setDatabaseName("template1");

    bool ok = m_database.open();

    if (ok)
    {

        qDebug() << "Borrando...";
        QSqlQuery q0("DROP DATABASE IF EXISTS app_doctest", m_database);
        if (q0.lastError().type() == QSqlError::NoError)
        {
            qDebug() << "Creando...";
            QSqlQuery q1("CREATE DATABASE app_doctest", m_database);
            if (q1.lastError().type() == QSqlError::NoError)
            {
                m_database.close();
                m_database.setDatabaseName("app_doctest");
                m_database.open();

                /// Crea estructura en la base de datos
                QString sql {"CREATE TABLE usuarios ( \
                             id_user integer, \
                             name varchar(40),\
                             email varchar(40), \
                             password varchar(40),\
                             PRIMARY KEY(id_user) \
                )"};

                qDebug() << "Iniciando...";
                QSqlQuery q2(sql, m_database);
                if (q2.lastError().type() == QSqlError::NoError)
                {
                    result = true;
                } // end if
            }
            else
            {
                qDebug() << "BB:" << m_database.lastError().text();
            } // end if

        }
        else
        {
            qDebug() << "AA:" << m_database.lastError().text();
        } // end if

    } // end if

    return result;
}

QSqlError Bbdd::lastError()
{
    return m_database.lastError();
}




