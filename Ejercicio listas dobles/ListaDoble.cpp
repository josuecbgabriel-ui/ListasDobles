#include "ListaDoble.h"
#include <iostream>
#include <fstream>

ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

ListaDoble::~ListaDoble() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void ListaDoble::insertarFinal(const Persona& persona) {
    Nodo* nuevo = new Nodo(persona);
    if (!cabeza) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

bool ListaDoble::existePrefijoCorreo(const std::string& prefijo) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::string correoActual = actual->persona.getCorreo();
        size_t posArroba = correoActual.find('@');
        if (posArroba != std::string::npos) {
            std::string prefijoActual = correoActual.substr(0, posArroba);
            if (prefijoActual == prefijo) return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void ListaDoble::mostrarLista() const {
    if (!cabeza) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    std::cout << "\n================= LISTA DE REGISTROS =================" << std::endl;
    while (actual != nullptr) {
        std::cout << "Cédula:    " << actual->persona.getCedula() << std::endl;
        std::cout << "Nombres:   " << actual->persona.getNombres() << std::endl;
        std::cout << "Apellidos: " << actual->persona.getApellidos() << std::endl;
        std::cout << "Correo:    " << actual->persona.getCorreo() << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        actual = actual->siguiente;
    }
}

void ListaDoble::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo para guardar datos." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo << "Cédula   " << actual->persona.getCedula() << "\n";
        archivo << "Nombres: " << actual->persona.getNombres() << "\n";
        archivo << "Apellidos: " << actual->persona.getApellidos() << "\n";
        archivo << "Correo: " << actual->persona.getCorreo() << "\n";
        archivo << "-------------------------------------------\n";
        actual = actual->siguiente;
    }

    archivo.close();
    std::cout << "Datos guardados correctamente en '" << nombreArchivo << "'." << std::endl;
}