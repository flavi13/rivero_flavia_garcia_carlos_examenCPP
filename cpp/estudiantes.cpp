//
// Created by Flavia Rivero on 21/11/24.
//
#include "Estudiantes.h"
#include "excepciones.h"
#include <algorithm>
#include <iostream>

Estudiante::Estudiante(const std::string& nombre, int edad, float promedio)
    : nombre(nombre), edad(edad), promedio(promedio) {}

void Estudiante::mostrarEstudiante() const {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Promedio: " << promedio << "\n";
}

void Estudiante::agregarMateria(const std::string& materia) {
    materias.push_back(materia);
}

void Estudiante::eliminarMateria(const std::string& materia) {
    auto it = std::find(materias.begin(), materias.end(), materia);
    if (it != materias.end()) {
        materias.erase(it);
        // Remove associated attendance records
        asistencias.erase(std::remove_if(asistencias.begin(), asistencias.end(),
            [&materia](const Asistencia& asistencia) {
                return asistencia.getMateria() == materia;
            }), asistencias.end());
    } else {
        throw MateriaNoEncontrada(materia);
    }
}

void Estudiante::mostrarMaterias() const {
    std::cout << "Materias:\n";
    for (const auto& materia : materias) {
        std::cout << "- " << materia << "\n";
    }
}

void Estudiante::registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
    if (std::find(materias.begin(), materias.end(), materia) == materias.end()) {
        throw MateriaNoEncontrada(materia);
    }
    asistencias.emplace_back(fecha, materia, estado);
}

void Estudiante::mostrarAsistencias() const {
    std::cout << "Asistencias:\n";
    for (const auto& asistencia : asistencias) {
        asistencia.mostrarAsistencia();
    }
}