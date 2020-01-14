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
public:
    std::string url;
    std::string like;
    std::string size;
};

#endif // PHOTO_H
