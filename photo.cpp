#include "photo.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QFile>
#include "style.h"
#include "user.h"

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
bool Photo::createPhoto()
{

    QSqlQuery query;
    query.prepare("INSERT into photo (url,size,mg,id_user,idstyle) values (:uurl,:siize,:like,:iduser,:idstyle)");


    query.bindValue(":uurl", QString::fromStdString(m_url));
    query.bindValue(":siize", QString::fromStdString(m_size));
    query.bindValue(":like", m_like);
    query.bindValue(":iduser", m_idUser);
    query.bindValue(":idstyle", m_idStyle);
    query.exec();

    return true;

}

json Photo::toJSON()
{
    json photo;

    photo["id"] = m_id;
    photo["uurl"] = m_url;
    photo["siize"] = m_like;
    photo["like"] = m_size;
    photo["iduser"]=m_idUser;
    photo["idstyle"]=m_idStyle;
    return photo;
}

json Photo::base64JSON()
{

    Style estilo;
    estilo.load(m_idStyle);

    User usuario("", "", "");
    usuario.load(m_idUser);

    json photo;
    photo["id"] = m_id;
    photo["uurl"] = m_url;
    photo["siize"] = m_like;
    photo["like"] = m_size;
    photo["iduser"] = usuario.getNombre();
    photo["estilo"] = estilo.getTipo();

    QString img("./imagenes/" + QString::fromUtf8(m_url.c_str()));
    QFile* file = new QFile(img);
    file->open(QIODevice::ReadOnly);
    QByteArray image = file ->readAll();

    QString base64 = QString(image.toBase64());

    photo["base64"] =  base64.toUtf8().constData();

    return photo;

}

void Photo::saveImage(QString base64, std::string name)
{

    QStringList strings = base64.split("base64,");
    QString b64 = strings.value(1);

    QByteArray imageData = QByteArray::fromBase64(b64.toUtf8());
    QImage img;
    img = QImage::fromData(imageData, "JPG");

    if(img.isNull()) qDebug() << "No imagen";
    else
    {

        img.save("./imagenes/" + QString::fromUtf8(name.c_str()));

    }

}

std::list<Photo> Photo::find(int idUser)
{

    std::list<Photo> fotos{};

    QSqlQuery query;
    query.prepare("SELECT * FROM photo WHERE id_user=:iduser");
    query.bindValue(":iduser",idUser);
    query.exec();

    while (query.next())
    {

        QString url = query.value("url").toString();
        int like = query.value("mg").toInt();
        int size = query.value("size").toInt();
        int idUser = query.value("id_user").toInt();
        int idStyle = query.value("idstyle").toInt();

        QString s = "" + size;
        Photo foto(url.toUtf8().constData(), like, s.toUtf8().constData(), idStyle, idUser);
        foto.m_id = query.value("id_photo").toInt();

        fotos.push_back(foto);

    }

    return fotos;

}

std::list<Photo> Photo::find()
{

    std::list<Photo> fotos{};

    QSqlQuery query;
    query.prepare("SELECT * FROM photo");
    query.exec();

    while (query.next())
    {

        QString url = query.value("url").toString();
        int like = query.value("mg").toInt();
        int size = query.value("size").toInt();
        int idUser = query.value("id_user").toInt();
        int idStyle = query.value("idstyle").toInt();

        QString s = "" + size;
        Photo foto(url.toUtf8().constData(), like, s.toUtf8().constData(), idStyle, idUser);
        foto.m_id = query.value("id_photo").toInt();

        fotos.push_back(foto);

    }

    return fotos;

}



















