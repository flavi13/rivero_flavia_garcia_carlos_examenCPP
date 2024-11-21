//
// Created by Flavia Rivero on 21/11/24.
//

#include "excepciones.h"

MateriaNoEncontrada::MateriaNoEncontrada(const std::string& materia)
    : materia(materia), mensaje("Materia no encontrada: " + materia) {}

const char* MateriaNoEncontrada::what() const noexcept {
    return mensaje.c_str();
}

FormatoFechaInvalido::FormatoFechaInvalido(const std::string& fecha)
    : fecha(fecha), mensaje("Error: " + fecha + " no es una fecha valida") {}

const char* FormatoFechaInvalido::what() const noexcept {
    return mensaje.c_str();
}
