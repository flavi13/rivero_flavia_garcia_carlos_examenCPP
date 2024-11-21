//
// Created by Flavia Rivero on 21/11/24.
//

#include "utils.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <limits>

bool validarFecha(const std::string& fecha) {
    std::regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
    if (!std::regex_match(fecha, formatoFecha)) {
        return false;
    }

    std::istringstream ss(fecha);
    std::string token;
    int year, month, day;

    std::getline(ss, token, '-');
    year = std::stoi(token);
    std::getline(ss, token, '-');
    month = std::stoi(token);
    std::getline(ss, token, '-');
    day = std::stoi(token);

    return (month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

bool validarEstado(const std::string& estado) {
    return estado == "asistio" || estado == "falta" || estado == "tardanza";
}

bool validarNumero(const std::string& str) {
    return std::regex_match(str, std::regex("^[0-9]+$"));
}

bool validarPromedio(const std::string& str) {
    return std::regex_match(str, std::regex("^[0-9]+(\\.[0-9]+)?$"));
}

void solicitarDatosEstudiante(Estudiante& estudiante) {
    std::string nombre;
    std::string edadStr;
    std::string promedioStr;
    std::string numMateriasStr;
    int edad;
    float promedio;
    int numMaterias;

    // Solicitar datos del estudiante
    std::cout << "Ingrese el nombre del estudiante: ";
    std::getline(std::cin, nombre);

    // Validar la edad
    while (true) {
        std::cout << "Ingrese la edad del estudiante: ";
        std::getline(std::cin, edadStr);
        if (!validarNumero(edadStr) || (edad = std::stoi(edadStr)) <= 0) {
            std::cerr << "Error: no es una edad valida\n";
        } else {
            break;
        }
    }

    // Validar el promedio
    while (true) {
        std::cout << "Ingrese el promedio del estudiante: ";
        std::getline(std::cin, promedioStr);
        if (!validarPromedio(promedioStr) || (promedio = std::stof(promedioStr)) < 0.0 || promedio > 10.0) {
            std::cerr << "Error: no es un promedio valido\n";
        } else {
            break;
        }
    }

    // Asignar valores al estudiante
    estudiante = Estudiante(nombre, edad, promedio);

    // Validar el número de materias
    while (true) {
        std::cout << "Ingrese el numero de materias: ";
        std::getline(std::cin, numMateriasStr);
        if (!validarNumero(numMateriasStr) || (numMaterias = std::stoi(numMateriasStr)) <= 0) {
            std::cerr << "Error: no es un numero de materias valido\n";
        } else {
            break;
        }
    }

    // Agregar materias
    std::string materia;
    for (int i = 0; i < numMaterias; ++i) {
        std::cout << "Materia " << (i + 1) << ": ";
        std::getline(std::cin, materia);
        estudiante.agregarMateria(materia);
    }

    // Mostrar datos del estudiante
    std::cout << "Datos del estudiante:\n";
    estudiante.mostrarEstudiante();
    estudiante.mostrarMaterias();
}

void registrarAsistencias(Estudiante& estudiante) {
    std::string fecha, materia, estado;
    std::cout << "Ingrese las asistencias (escriba 'fin' para terminar):\n";
    while (true) {
        std::cout << "Fecha (YYYY-MM-DD): ";
        std::getline(std::cin, fecha);
        if (fecha == "fin") break;
        if (!validarFecha(fecha)) {
            std::cerr << "Error: " << fecha << " no es una fecha valida\n";
            continue;
        }
        std::cout << "Materia: ";
        std::getline(std::cin, materia);
        std::cout << "Estado (asistio/falta/tardanza): ";
        std::getline(std::cin, estado);
        if (!validarEstado(estado)) {
            std::cerr << "Estado incorrecto. Intente nuevamente.\n";
            continue;
        }
        estudiante.registrarAsistencia(fecha, materia, estado);
    }

    // Mostrar asistencias del estudiante
    std::cout << "Datos del estudiante despues de registrar asistencias:\n";
    estudiante.mostrarAsistencias();
}

void preguntarEliminarMateria(Estudiante& estudiante) {
    std::string respuesta;
    std::cout << "Quieres eliminar una materia? (si/no): ";
    std::getline(std::cin, respuesta);

    if (respuesta == "si") {
        std::string materia;
        std::cout << "Ingrese una materia para eliminar: ";
        std::getline(std::cin, materia);
        estudiante.eliminarMateria(materia); // Esto deberia lanzar una excepcion si la materia no existe

        // Mostrar datos del estudiante despues de eliminar la materia
        std::cout << "Datos del estudiante despues de eliminar la materia:\n";
        estudiante.mostrarEstudiante();
        estudiante.mostrarMaterias();
        estudiante.mostrarAsistencias();
    }
}
