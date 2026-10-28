#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"
#include <string>

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoble();
    ~ListaDoble();

    void insertarFinal(const Persona& persona);
    bool existePrefijoCorreo(const std::string& prefijo) const;
    void mostrarLista() const;
    void guardarEnArchivo(const std::string& nombreArchivo) const;
};

#endif