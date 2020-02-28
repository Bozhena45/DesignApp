#ifndef STYLE_H
#define STYLE_H
#include "json.hpp"

using json = nlohmann::json;

/**
 * @brief La clase Estilo
 *
 * Esta clase sirve para poder elegir el tipo de estilo que queremos subir en nuestra aplicación
 * y al ponerlo se añadirá en la bbdd que está relacionada con la clase foto
 */
class Style
{
public:
    Style();
    /**
     * @brief El método Load
     *
     * Este método te permite buscar en la bbdd el tipo de estilo
     * @param tipo
     */
    bool Load(std::string tipo);

    /**
     * @brief El método getId
     *
     * Sirve para cambiar el ID que es un parámetro privado
     * @return
     */
    int getID();

private:
    int m_idStyle;
    std::string m_tipo;
};

#endif // STYLE_H
