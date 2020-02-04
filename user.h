#ifndef USER_H
#define USER_H
#include "json.hpp"

using json = nlohmann::json;

class User
{
public:
    ///Los metodos
    User(std::string nombre,std::string email,std::string password);
    void createUser();

    static json userList(json&);
    json toJSON();
    static User load(std::string usuario,std::string contrasenya);
    static User loadN(std::string name);

    void setId(int id);


private:
    ///Los parámetros del usuario
    int m_id;
    std::string m_nombre;
    std::string m_email;
    std::string m_password;
};

#endif // USER_H
