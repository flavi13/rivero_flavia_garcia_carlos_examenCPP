#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fecha[11];
    char materia[50];
    char estado[20];
} Asistencia;

void inicializarAsistencia(Asistencia* asistencia, const char* fecha, const char* materia, const char* estado) {
    if (strlen(fecha) != 10 || fecha[4] != '-' || fecha[7] != '-') {
        fprintf(stderr, "Formato de fecha inválido: %s\n", fecha);
        exit(EXIT_FAILURE);
    }
    strncpy(asistencia->fecha, fecha, 11);
    strncpy(asistencia->materia, materia, 50);
    strncpy(asistencia->estado, estado, 20);
}

void mostrarAsistencia(const Asistencia* asistencia) {
    printf("Fecha: %s, Materia: %s, Estado: %s\n", asistencia->fecha, asistencia->materia, asistencia->estado);
}

const char* getMateria(const Asistencia* asistencia) {
    return asistencia->materia;
}