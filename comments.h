#ifndef COMMENTS_H
#define COMMENTS_H
#include "json.hpp"

using json = nlohmann::json;


class Comments
{
public:
    Comments();
    Comments(std::string comment,int idPhoto,int idUser);
    void CreateComment();
    json toJSON();
    void setId(int id);

private:
    int m_idComment;
    std::string m_comment;
    int m_idPhoto;
    int m_idUser;
};

#endif // COMMENTS_H
