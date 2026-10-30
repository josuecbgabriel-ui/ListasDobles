#include "Validador.h"
#include <cctype>
#include <algorithm>
#include <sstream>

bool Validador::esNombresValido(const std::string& texto) {
    if (texto.empty()) return false;
    std::stringstream ss(texto);
    std::string n1, n2, extra;
    ss >> n1 >> n2 >> extra;

    // Permite 1 o 2 nombres, asegurando que no haya un tercer nombre ni espacios vacios invalidos
    if (n1.empty() || !extra.empty()) return false;

    for (char c : n1) {
        if (!isalpha(c)) return false;
    }
    if (!n2.empty()) {
        for (char c : n2) {
            if (!isalpha(c)) return false;
        }
    }
    return true;
}

bool Validador::esApellidosValido(const std::string& texto) {
    if (texto.empty()) return false;
    std::stringstream ss(texto);
    std::string a1, a2, extra;
    ss >> a1 >> a2 >> extra;

    // Los dos apellidos son obligatorios (exactamente dos palabras)
    if (a1.empty() || a2.empty() || !extra.empty()) return false;

    for (char c : a1) {
        if (!isalpha(c)) return false;
    }
    for (char c : a2) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool Validador::esCedulaValida(const std::string& cedula) {
    if (cedula.length() != 10) return false;
    for (char c : cedula) {
        if (!isdigit(c)) return false;
    }
    return true;
}

std::string Validador::normalizar(std::string texto) {
    std::transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}