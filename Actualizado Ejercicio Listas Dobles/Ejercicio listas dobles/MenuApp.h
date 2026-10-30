#ifndef MENUAPP_H
#define MENUAPP_H

#include "ListaDoble.h"
#include <string>

class MenuApp {
private:
    ListaDoble lista;
    std::string pedirDatoValidado(const std::string& mensaje, bool (*funcValidacion)(const std::string&));

public:
    void ejecutar();
};

#endif
