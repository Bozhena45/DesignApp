#include "photo.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
Photo::Photo()
{

}

Photo::Photo(std::string url,int like,std::string size,int idStyle,int idUser)
{

    this->m_url=url;
    this->m_like=like;
    this->m_size=size;
    this->m_idUser=idUser;
    this->m_idStyle=idStyle;

}


///2)Subir photo:
/// 2.1) Hacemos la query del insert(para añadir una nueva foto a la tabla de photo que está relacionada con la tabla usuario )
/// 2.2) Lo pasamos a JSON
void Photo::createPhoto()
{

    QSqlQuery query;
    query.prepare("INSERT into photo (url,size,mg,id_user,idstyle) values (:uurl,:siize,:like,:iduser,:idstyle)");


    query.bindValue(":uurl", QString::fromStdString(m_url));
    query.bindValue(":siize", QString::fromStdString(m_size));
    query.bindValue(":like", m_like);
    query.bindValue(":iduser", m_idUser);
    query.bindValue(":idstyle", m_idStyle);
    query.exec();

}

json Photo::toJSON()
{
    json photo;

    photo["uurl"] = m_url;
    photo["siize"] = m_like;
    photo["like"] = m_size;
    photo["iduser"]=m_idUser;
    photo["idstyle"]=m_idStyle;
    return photo;
}




