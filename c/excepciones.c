#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char materia[50];
    char mensaje[100];
} MateriaNoEncontrada;

typedef struct {
    char fecha[11];
    char mensaje[100];
} FormatoFechaInvalido;

void inicializarMateriaNoEncontrada(MateriaNoEncontrada* error, const char* materia) {
    strncpy(error->materia, materia, 50);
    snprintf(error->mensaje, 100, "Materia no encontrada: %s", materia);
}

const char* obtenerMensajeMateriaNoEncontrada(const MateriaNoEncontrada* error) {
    return error->mensaje;
}

void inicializarFormatoFechaInvalido(FormatoFechaInvalido* error, const char* fecha) {
    strncpy(error->fecha, fecha, 11);
    snprintf(error->mensaje, 100, "Error: %s no es una fecha valida", fecha);
}

const char* obtenerMensajeFormatoFechaInvalido(const FormatoFechaInvalido* error) {
    return error->mensaje;
}