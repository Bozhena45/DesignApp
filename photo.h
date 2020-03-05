#ifndef PHOTO_H
#define PHOTO_H
#include "json.hpp"

using json = nlohmann::json;

/**
 * @brief Clase para el manejo de Fotos
 *
 * Esta clase sirve para la creación de la url de una foto y poder insertarla dentro de la base de datos,
 * tambien sirve para crear un JSON a partir de la libreria json = nlohmann::json, y este mensaje
 * JSON es lo que se le enviará al cliente
 */
class Photo
{
public:
    Photo();
    Photo(std::string url,int like,std::string size,int idStyle,int idUser);

    /**
     * @brief El método createPhoto
     *
     * Este método sirve para crear una foto dentro de la base de datos. Para crear una foto
     * necesitaríamos los parámentros que están en el constructor.
     * En este caso, no se subiría una foto en la aplicación  sino la url de la foto.
     */
    bool createPhoto();
    /**
     * @brief El método toJSON
     *
     * Sirve para crear un JSON a partir de la libreria json = nlohmann::json, y este mensaje
     * JSON es lo que se le enviará al cliente
     *
     * @return Devuelve el mensaje  JSON
     */
    json toJSON();
    /**
     * @brief El método setId
     *
     * Sirve para cambiar el ID que es un parámetro privado
     * @param id
     */
    void setId(int id);
private:
    int m_id;
    std::string m_url;
    int m_like;
    std::string m_size;
    int m_idStyle;
    int m_idUser;
};

#endif // PHOTO_H
