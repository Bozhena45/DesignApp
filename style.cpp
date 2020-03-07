#include "style.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

Style::Style()
{

}

bool Style::Load(std::string tipo)
{

    QSqlQuery query;
    query.prepare("Select * from style where tipo=:tipo");
    query.bindValue(":tipo",QString::fromUtf8(tipo.c_str()));
    query.exec();

    if (query.next())
    {
        int id = query.value("id_style").toInt();
        QString type = query.value("tipo").toString();

        m_idStyle = id;
        m_tipo=type.toUtf8().constData();

        return true;
    }

  return false;

}

void Style::load(int id)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM style WHERE id_style=:id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next())
    {
        int id = query.value("id_style").toInt();
        QString type = query.value("tipo").toString();

        m_idStyle = id;
        m_tipo = type.toUtf8().constData();

    }

}

int Style::getID()
{
    return m_idStyle;
}

std::string Style::getTipo()
{
    return m_tipo;
}




















