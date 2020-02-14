#ifndef BBDD_H
#define BBDD_H

#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QSqlError>
#include <QDebug>

class Bbdd
{

public:
    Bbdd();
    ~Bbdd();
    bool init();
    void close();
    QSqlError lastError();
    bool insert();

private:
    QSqlDatabase m_database;
};

#endif // BBDD_H
