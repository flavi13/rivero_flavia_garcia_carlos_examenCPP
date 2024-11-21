//
// Created by Flavia Rivero on 21/11/24.
//

#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include <string>
#include <vector>
#include "asistencia.h"

class Estudiante {
public:
    Estudiante(const std::string& nombre, int edad, float promedio);
    void mostrarEstudiante() const;
    void agregarMateria(const std::string& materia);
    void eliminarMateria(const std::string& materia);
    void mostrarMaterias() const;
    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado);
    void mostrarAsistencias() const;

private:
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
    std::vector<Asistencia> asistencias;
};

#endif // ESTUDIANTES_H