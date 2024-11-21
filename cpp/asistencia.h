//
// Created by Flavia Rivero on 21/11/24.
//
#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include <string>
#include "excepciones.h"

class Asistencia {
public:
    Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado);
    void mostrarAsistencia() const;
    std::string getMateria() const; // Add this declaration

private:
    std::string fecha;
    std::string materia;
    std::string estado;
};

#endif // ASISTENCIA_H