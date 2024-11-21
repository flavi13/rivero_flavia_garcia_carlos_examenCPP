#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 50
#define MAX_ASISTENCIAS 100

typedef struct {
    char fecha[11];
    char materia[50];
    char estado[20];
} Asistencia;

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][50];
    int num_materias;
    Asistencia asistencias[MAX_ASISTENCIAS];
    int num_asistencias;
} Estudiante;

void inicializarEstudiante(Estudiante* estudiante, const char* nombre, int edad, float promedio) {
    strncpy(estudiante->nombre, nombre, 50);
    estudiante->edad = edad;
    estudiante->promedio = promedio;
    estudiante->num_materias = 0;
    estudiante->num_asistencias = 0;
}

void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", estudiante->nombre, estudiante->edad, estudiante->promedio);
}

void agregarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante->num_materias < MAX_MATERIAS) {
        strncpy(estudiante->materias[estudiante->num_materias], materia, 50);
        estudiante->num_materias++;
    } else {
        fprintf(stderr, "No se pueden agregar más materias\n");
    }
}

void eliminarMateria(Estudiante* estudiante, const char* materia) {
    int found = 0;
    for (int i = 0; i < estudiante->num_materias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            found = 1;
            for (int j = i; j < estudiante->num_materias - 1; j++) {
                strncpy(estudiante->materias[j], estudiante->materias[j + 1], 50);
            }
            estudiante->num_materias--;
            break;
        }
    }
    if (!found) {
        fprintf(stderr, "Materia no encontrada: %s\n", materia);
    } else {
        // Eliminar asistencias asociadas
        for (int i = 0; i < estudiante->num_asistencias; ) {
            if (strcmp(estudiante->asistencias[i].materia, materia) == 0) {
                for (int j = i; j < estudiante->num_asistencias - 1; j++) {
                    estudiante->asistencias[j] = estudiante->asistencias[j + 1];
                }
                estudiante->num_asistencias--;
            } else {
                i++;
            }
        }
    }
}

void mostrarMaterias(const Estudiante* estudiante) {
    printf("Materias:\n");
    for (int i = 0; i < estudiante->num_materias; i++) {
        printf("- %s\n", estudiante->materias[i]);
    }
}

void registrarAsistencia(Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    int found = 0;
    for (int i = 0; i < estudiante->num_materias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        fprintf(stderr, "Materia no encontrada: %s\n", materia);
        return;
    }
    if (estudiante->num_asistencias < MAX_ASISTENCIAS) {
        strncpy(estudiante->asistencias[estudiante->num_asistencias].fecha, fecha, 11);
        strncpy(estudiante->asistencias[estudiante->num_asistencias].materia, materia, 50);
        strncpy(estudiante->asistencias[estudiante->num_asistencias].estado, estado, 20);
        estudiante->num_asistencias++;
    } else {
        fprintf(stderr, "No se pueden registrar más asistencias\n");
    }
}

void mostrarAsistencias(const Estudiante* estudiante) {
    printf("Asistencias:\n");
    for (int i = 0; i < estudiante->num_asistencias; i++) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}