#ifndef STYLE_H
#define STYLE_H
#include "json.hpp"

using json = nlohmann::json;


class Style
{
public:
    Style();

private:
    int m_idStyle;
    std::string m_tipo;
    int m_idUser;
    int m_idPhoto;
};

#endif // STYLE_H
