#include "MenuApp.h"
#include "Validador.h"
#include "GeneradorCorreo.h"
#include <iostream>

std::string MenuApp::pedirDatoValidado(const std::string& mensaje, bool (*funcValidacion)(const std::string&)) {
    std::string entrada;
    do {
        std::cout << mensaje;
        std::getline(std::cin, entrada);
        if (!funcValidacion(entrada)) {
            std::cout << "[ERROR] Entrada inválida. Por favor, reintente.\n";
        }
    } while (!funcValidacion(entrada));
    return entrada;
}

void MenuApp::ejecutar() {
    int opcion = 0;
    do {
        std::cout << "\n================ MENÚ PRINCIPAL ================\n";
        std::cout << "1. Agregar Estudiante\n";
        std::cout << "2. Mostrar Estudiantes\n";
        std::cout << "3. Guardar en Archivo .TXT\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1: {
            std::string cedula = pedirDatoValidado("Ingrese Cédula: ", Validador::esCedulaValida);
            std::string nombres = pedirDatoValidado("Ingrese Nombres: ", Validador::esTextoValido);
            std::string apellidos = pedirDatoValidado("Ingrese Apellidos: ", Validador::esTextoValido);

            std::string correoGenerado = GeneradorCorreo::generarCorreo(nombres, apellidos, lista);

            Persona nuevaPersona(cedula, nombres, apellidos, correoGenerado);
            lista.insertarFinal(nuevaPersona);

            std::cout << "\n[ÉXITO] Estudiante registrado exitosamente!" << std::endl;
            std::cout << "Correo Asignado: " << correoGenerado << std::endl;
            break;
        }
        case 2:
            lista.mostrarLista();
            break;
        case 3:
            lista.guardarEnArchivo("estudiantes.txt");
            break;
        case 4:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 4);
}