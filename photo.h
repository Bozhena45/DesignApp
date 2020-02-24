#ifndef PHOTO_H
#define PHOTO_H
#include "json.hpp"

using json = nlohmann::json;

class Photo
{
public:
    Photo();
    Photo(std::string url,std::string like,std::string size,int idStyle,int idUser);
    void createPhoto();
    json toJSON();

    void setId(int id);
private:
    int m_id;
    std::string m_url;
    std::string m_like;
    std::string m_size;
    int m_idStyle;
    int m_idUser;
};

#endif // PHOTO_H
