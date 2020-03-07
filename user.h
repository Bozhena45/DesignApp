#ifndef USER_H
#define USER_H
#include "json.hpp"

using json = nlohmann::json;
/**
 * @brief La clase user
 *
 * Esta clase sirve para crear, buscar , generar/crear un JSON a partir de la libreria json = nlohmann::json
 *
 *
 */
class User
{
public:
    /**
     * @brief El constructor User
     * @param nombre
     * @param email
     * @param password
     */
    User(std::string nombre,std::string email,std::string password);
    /**
     * @brief El método createUser
     *
     * Este método sirve para crear un usuario ,es decir,
     * para crear un usuario tenemos que insertar en la base de datos nombre,email y contraseña
     *
     *
     */

    bool createUser();
    /**
     * @brief El método toJSON
     *
     * Sirve para crear un JSON a partir de la libreria json = nlohmann::json, y este mensaje
     * JSON es lo que se le enviará al cliente
     *
     * @return Devuelve el mensaje pero en JSON
     */
    json toJSON();
    /**
     * @brief El método load
     *
     * Este método sirve para poder buscar(hacer una select en la base de datos) el usuario con su información que en este
     * caso sería su  email y contraseña, la contraseña no se verá puesto que es una contraseña cifrada
     * @param usuario
     * @param contrasenya
     * @return Nos devuelve el usuario con su email y su contraseña
     */
    static User load(std::string usuario,std::string contrasenya);

    /**
     * @brief El método loadN
     *
     * Este método es muy parecido al anterior puesto que también haríamos una select en la base de datos
     * para poder buscar el usuario, pero en este caso sólo le pasaríamos su nombre
     * @param name
     * @return Nos devuelve el usuario con su nombre
     */
    static User loadN(std::string name);
    /**
     * @brief El método setId
     *
     * Sirve para cambiar el ID que es un parámetro privado
     * @param id
     */
    void setId(int id);
    void load(int id);
    std::string getNombre();

private:
    ///Los parámetros del usuario
    int m_id;
    std::string m_nombre;
    std::string m_email;
    std::string m_password;
};

#endif // USER_H
