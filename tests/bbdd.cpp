#include "bbdd.h"

Bbdd::Bbdd()
{

}

bool Bbdd::init(){

    m_database = QSqlDatabase::addDatabase("QPSQL");
    m_database.setHostName("localhost");
    m_database.setDatabaseName("template1");
    m_database.setPort(5432);
    m_database.setHostName("postgres");
    m_database.setPassword("");
    bool ok = m_database.open();

    if(ok)
    {

        QSqlQuery q0("DROP DATABASE IF EXISTS app_doctest",m_database);

        if (q0.lastError().type() == QSqlError::NoError)
        {
              QSqlQuery q1("CREATE DATABASE app_doctest",m_database);
              if (q1.lastError().type() == QSqlError::NoError)
              {
                  m_database.close();
                   m_database.setDatabaseName("app_doctest");
                  m_database.open();


                 ///Crear estructura base de datos
                  QString sql{"CREATE TABLE usuarios ( \
                    id_user integer, \
                    name varchar(40),\
                    email varchar(40), \
                    password varchar(40),\
                    PRIMARY KEY(id_user) \
                     )"};

                  }

              } // end if

        } // end if

        return ok;
    }
