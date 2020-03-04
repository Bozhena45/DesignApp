#ifndef COMMENTS_H
#define COMMENTS_H
#include "json.hpp"
#include <list>

using json = nlohmann::json;
/**
 * @brief La clase comentarios
 *
 * Esta clase sirve para poder crear un comentario y se pueda añadir a la imagen
 * Los metodos que tiene esta clase son: crear un comentario y pasar los mensajes a json
 */

class Comments
{
public:

    /**
     * @brief Los constructores de la clase comentario
     */
    Comments();
    Comments(std::string comment,int idPhoto,int idUser);

    /**
     * @brief CreateComment
     *
     * A partir de este método crearíamos nuestro comentario
     */
    bool CreateComment();

    /**
     * @brief toJSON
     *
     * Se podrá generar/crear un JSON a partir de la libreria json = nlohmann::json
     * @return Este método devuelve los mensajes en forma de json
     */
    json toJSON();
    /**
     * @brief setId
     *
     *  Sirve para cambiar el ID que es un parámetro privado
     * @param id
     */


    /**
     * @brief Devuelve la lista de comentarios de una foto
     * @param id_photo
     * @return
     */
    static std::list<Comments> find (int id_photo);
    void setId(int id);

private:
    int m_idComment;
    std::string m_comment;
    int m_idPhoto;
    int m_idUser;
};

#endif // COMMENTS_H
