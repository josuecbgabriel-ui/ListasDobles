#ifndef GENERADORCORREO_H
#define GENERADORCORREO_H

#include "ListaDoble.h"
#include <string>

class GeneradorCorreo {
public:
    static std::string generarCorreo(const std::string& nombres, const std::string& apellidos, const ListaDoble& lista);
};

#endif