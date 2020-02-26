#include "comments.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
Comments::Comments()
{

}

Comments::Comments(std::string comment,int idPhoto,int idUser)
{

   this->m_idUser = idUser;
   this->m_comment = comment;
   this->m_idPhoto = idPhoto;
}

void Comments::CreateComment()
{

    QSqlQuery query;
    query.prepare("INSERT into comment (comment,id_user,idphoto) values (:comment,:iduser,:idphoto)");


    query.bindValue(":comment", QString::fromStdString(m_comment));
    query.bindValue(":iduser", m_idUser);
    query.bindValue(":idphoto", m_idPhoto);
    query.exec();

}

json Comments::toJSON()
{
    json comment;

    comment["comment"] = m_comment;
    comment["iduser"]=m_idUser;
    comment["idphoto"]=m_idPhoto;
    return comment;
}
