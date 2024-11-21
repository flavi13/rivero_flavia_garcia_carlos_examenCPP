#include "asistencia.h"
#include <iostream>
Asistencia::Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
    : fecha(fecha), materia(materia), estado(estado) {
    // Verificar formato de fecha simple (AAAA-MM-DD)
    if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        throw FormatoFechaInvalido(fecha);
    }
}

void Asistencia::mostrarAsistencia() const {
    std::cout << "Fecha: " << fecha
              << ", Materia: " << materia
              << ", Estado: " << estado << "\n";
}

std::string Asistencia::getMateria() const {
    return materia;
}