#ifndef USER_H
#define USER_H
#include "json.hpp"

using json = nlohmann::json;

class User
{
public:
    User(std::string nombre,std::string email,std::string password);
    void createUser();
    static json userList(json&);
    json toJSON();

private:
    int m_id;
    std::string m_nombre;
    std::string m_email;
    std::string m_password;
};

#endif // USER_H
