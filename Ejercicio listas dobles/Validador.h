#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>

class Validador {
public:
    static bool esTextoValido(const std::string& texto);
    static bool esCedulaValida(const std::string& cedula);
    static std::string normalizar(std::string texto);
};

#endif