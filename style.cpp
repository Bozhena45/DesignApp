#include "style.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

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

int Style::getID()
{
    return m_idStyle;
}
