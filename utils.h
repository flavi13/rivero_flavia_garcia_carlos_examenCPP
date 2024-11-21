//
// Created by Flavia Rivero on 21/11/24.
//
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Estudiantes.h"

bool validarFecha(const std::string& fecha);
bool validarEstado(const std::string& estado);
void solicitarDatosEstudiante(Estudiante& estudiante);
void registrarAsistencias(Estudiante& estudiante);
void preguntarEliminarMateria(Estudiante& estudiante); // Add this declaration

#endif // UTILS_H