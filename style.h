#ifndef STYLE_H
#define STYLE_H
#include "json.hpp"

using json = nlohmann::json;


class Style
{
public:
    Style();
    void Load(std::string tipo);
    int getID();

private:
    int m_idStyle;
    std::string m_tipo;
};

#endif // STYLE_H
