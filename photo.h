#ifndef PHOTO_H
#define PHOTO_H
#include "json.hpp"

using json = nlohmann::json;

class Photo
{
public:
    Photo();
    static json photoList(json&);
    static json deletePhoto(json&);

    Photo(std::string url,std::string like,std::string size);
    void createPhoto();
    json toJSON();

    void setId(int id);
private:
    int m_id;
    std::string m_url;
    std::string m_like;
    std::string m_size;
};

#endif // PHOTO_H
