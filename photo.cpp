#include "photo.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

Photo::Photo()
{

}
json Photo::photoList(json& mensaje)
{
    json persona1;
    json persona2;

    persona1["url"] = "https://pixabay.com/es/photos";
    persona1["like"] = "50";
    persona1["size"] = "64px";

    persona2["url"] = "https://pixabay.com/es";
    persona2["like"] = "20";
    persona2["size"] = "64px";

    json respuesta;

    respuesta["id"] = mensaje["id"];
    respuesta["lista"]["1"] = persona1;
    respuesta["lista"]["2"] = persona2;
    return respuesta;
}


///2)Subir photo:
/// 2.1) Hacemos la query del insert(para añadir una nueva foto a la tabla de photo que está relacionada con la tabla usuario )
/// 2.2) Lo pasamos a JSON
void Photo::createPhoto()
{

    QSqlQuery query;
    query.prepare("INSERT into photo (url,size,like) values (:uurl,:siize,:like)");


    query.bindValue(":uurl", QString::fromStdString(m_url));
    query.bindValue(":siize", QString::fromStdString(m_like));
    query.bindValue(":like", QString::fromStdString(m_size));
    query.exec();


}

json Photo::toJSON()
{
    json usuario;

    usuario["uurl"] = m_url;
    usuario["siize"] = m_like;
    usuario["like"] = m_size;
    return usuario;
}



json Photo::deletePhoto(json& mensaje)
{
    json persona1;
    json persona2;

    persona1["imageDelete"] = "5";
    persona2["imageDelete"] = "10";

    json respuesta;

    respuesta["id"] = mensaje["id"];
    respuesta["lista"]["1"] = persona1;
    respuesta["lista"]["2"] = persona2;

    return respuesta;
}
