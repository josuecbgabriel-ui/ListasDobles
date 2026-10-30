#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string cedula;
    std::string nombres;
    std::string apellidos;
    std::string correo;

public:
    Persona();
    Persona(std::string c, std::string n, std::string a, std::string e = "");

    std::string getCedula() const;
    void setCedula(const std::string& c);

    std::string getNombres() const;
    void setNombres(const std::string& n);

    std::string getApellidos() const;
    void setApellidos(const std::string& a);

    std::string getCorreo() const;
    void setCorreo(const std::string& e);
};

#endif