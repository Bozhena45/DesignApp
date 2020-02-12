#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QSqlError>
#include <QDebug>

class BaseDatos
{

public:
    BaseDatos();
    bool init();

private:
    QSqlDatabase m_database;

};

#endif // BASEDATOS_H
