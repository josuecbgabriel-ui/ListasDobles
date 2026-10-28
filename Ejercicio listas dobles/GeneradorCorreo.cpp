#include "GeneradorCorreo.h"
#include "Validador.h"
#include <sstream>

std::string GeneradorCorreo::generarCorreo(const std::string& nombres, const std::string& apellidos, const ListaDoble& lista) {
    std::stringstream ssNombres(nombres);
    std::stringstream ssApellidos(apellidos);
    std::string nom1, nom2, ape1, ape2;

    ssNombres >> nom1 >> nom2;
    ssApellidos >> ape1 >> ape2;

    nom1 = Validador::normalizar(nom1);
    nom2 = Validador::normalizar(nom2);
    ape1 = Validador::normalizar(ape1);

    std::string basePrefijo = "";

    if (!nom2.empty()) {
        basePrefijo = std::string(1, nom1[0]) + std::string(1, nom2[0]) + ape1;
    } else {
        basePrefijo = std::string(1, nom1[0]) + "_" + ape1;
    }

    int contador = 1;
    std::string prefijoFinal = basePrefijo + std::to_string(contador);

    while (lista.existePrefijoCorreo(prefijoFinal)) {
        contador++;
        prefijoFinal = basePrefijo + std::to_string(contador);
    }

    return prefijoFinal + "@espe.edu.ec";
}