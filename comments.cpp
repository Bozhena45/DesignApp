#include "comments.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
Comments::Comments()
{

}

Comments::Comments(std::string comment,int idUser,int idPhoto)
{

   this->m_idUser = idUser;
   this->m_comment = comment;
   this->m_idPhoto = idPhoto;
}

bool Comments::CreateComment()
{

    QSqlQuery query;
    query.prepare("INSERT into comment (comment,id_photo,id_user) values (:comment,:idphoto,:iduser)");

    query.bindValue(":comment", QString::fromStdString(m_comment));
    query.bindValue(":idphoto", m_idPhoto);
    query.bindValue(":iduser", m_idUser);
    query.exec();

    return true;
}

std::list<Comments> Comments::find (int id_photo)
{
    std::list<Comments> comentarios{};

    QSqlQuery query;
    query.prepare("SELECT * from comment where id_photo=:idphoto");
    query.bindValue(":idphoto",id_photo);
    query.exec();

    while (query.next())
    {

        QString comentario = query.value("comment").toString();
        int iduser = query.value("id_user").toInt();
        int idphoto = query.value("id_photo").toInt();

        Comments coment(comentario.toUtf8().constData(),iduser, idphoto);
        comentarios.push_back(coment);

    }

    return comentarios;
}

json Comments::toJSON()
{
    json comment;

    comment["comment"] = m_comment;
    comment["iduser"]=m_idUser;
    comment["idphoto"]=m_idPhoto;
    return comment;
}
