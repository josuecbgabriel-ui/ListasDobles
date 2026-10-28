#include "Validador.h"
#include <cctype>
#include <algorithm>

bool Validador::esTextoValido(const std::string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (!isalpha(c) && !isspace(c)) return false;
    }
    return true;
}

bool Validador::esCedulaValida(const std::string& cedula) {
    if (cedula.length() != 10) return false;
    for (char c : cedula) {
        if (!isdigit(c)) return false;
    }

    int provincia = std::stoi(cedula.substr(0, 2));
    if (provincia < 1 || provincia > 24) return false;

    int tercerDigito = cedula[2] - '0';
    if (tercerDigito >= 6) return false;

    int coeficientes[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        int producto = digito * coeficientes[i];
        if (producto >= 10) producto -= 9;
        suma += producto;
    }

    int digitoVerificadorCalculado = (10 - (suma % 10)) % 10;
    int digitoVerificadorReal = cedula[9] - '0';

    return digitoVerificadorCalculado == digitoVerificadorReal;
}

std::string Validador::normalizar(std::string texto) {
    std::transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}