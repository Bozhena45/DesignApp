#include "photo.h"

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
