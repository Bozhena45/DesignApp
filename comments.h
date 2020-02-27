#ifndef COMMENTS_H
#define COMMENTS_H
#include "json.hpp"

using json = nlohmann::json;
/**
 * @brief La clase comentarios
 *
 * Con esta clase podremos crear un comentario y coger el id puesto que es privado(lo cogeríamos a partir de un método)
 * Además  se podrá generar/crear un JSON a partir de la libreria json = nlohmann::json
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
    void CreateComment();

    /**
     * @brief toJSON
     * @return Este método devuelve los mensajes en forma de json
     */
    json toJSON();
    /**
     * @brief setId
     *
     *  Sirve para coger el ID que es un parámetro privado
     * @param id
     */

    void setId(int id);

private:
    int m_idComment;
    std::string m_comment;
    int m_idPhoto;
    int m_idUser;
};

#endif // COMMENTS_H
