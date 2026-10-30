#include "Persona.h"

Persona::Persona() : cedula(""), nombres(""), apellidos(""), correo("") {}

Persona::Persona(std::string c, std::string n, std::string a, std::string e)
    : cedula(c), nombres(n), apellidos(a), correo(e) {}

std::string Persona::getCedula() const { return cedula; }
void Persona::setCedula(const std::string& c) { cedula = c; }

std::string Persona::getNombres() const { return nombres; }
void Persona::setNombres(const std::string& n) { nombres = n; }

std::string Persona::getApellidos() const { return apellidos; }
void Persona::setApellidos(const std::string& a) { apellidos = a; }

std::string Persona::getCorreo() const { return correo; }
void Persona::setCorreo(const std::string& e) { correo = e; }