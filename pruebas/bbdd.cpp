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
    query.prepare("INSERT INTO usuario VALUES (:usuario)");
    query.bindValue(":usuario", "idUsuario");
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
                QString sql {"CREATE TABLE tabla ( \
                    id_usuario  SERIAL, \
                    nombre   varchar(40), \
                    PRIMARY KEY(id_tabla) \
                )"};

                qDebug() << "Iniciando...";
                QSqlQuery q2(sql, m_db);
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


























