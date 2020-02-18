#ifndef BBDD_H
#define BBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

class Bbdd
{
    QSqlDatabase m_db;
public:
    Bbdd();
    ~Bbdd();
    bool init();
    void close();
    QSqlError lastError();
    bool insert();
    //bool load(std::string nombre);
};

#endif // BBDD_H
