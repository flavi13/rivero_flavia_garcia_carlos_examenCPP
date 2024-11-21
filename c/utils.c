#include "Estudiantes.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int validarNumero(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int validarPromedio(const char* str) {
    int dotCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return 0;
            }
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int validarFecha(const char* fecha) {
    if (strlen(fecha) != 10) return 0;
    if (fecha[4] != '-' || fecha[7] != '-') return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(fecha[i])) return 0;
    }
    return 1;
}

int validarEstado(const char* estado) {
    return (strcmp(estado, "asistio") == 0 || strcmp(estado, "falta") == 0 || strcmp(estado, "tardanza") == 0);
}

int solicitarDatosEstudiante(Estudiante* estudiante) {
    char nombre[MAX_STR_LEN];
    char edadStr[MAX_STR_LEN];
    char promedioStr[MAX_STR_LEN];
    char numMateriasStr[MAX_STR_LEN];
    int edad;
    float promedio;
    int numMaterias;

    printf("Ingrese el nombre del estudiante: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    while (1) {
        printf("Ingrese la edad del estudiante: ");
        fgets(edadStr, sizeof(edadStr), stdin);
        edadStr[strcspn(edadStr, "\n")] = '\0';
        if (!validarNumero(edadStr) || (edad = atoi(edadStr)) <= 0) {
            fprintf(stderr, "Error: no es una edad valida\n");
        } else {
            break;
        }
    }

    while (1) {
        printf("Ingrese el promedio del estudiante: ");
        fgets(promedioStr, sizeof(promedioStr), stdin);
        promedioStr[strcspn(promedioStr, "\n")] = '\0';
        if (!validarPromedio(promedioStr) || (promedio = atof(promedioStr)) < 0.0 || promedio > 10.0) {
            fprintf(stderr, "Error: no es un promedio valido\n");
        } else {
            break;
        }
    }

    inicializarEstudiante(estudiante, nombre, edad, promedio);

    while (1) {
        printf("Ingrese el numero de materias: ");
        fgets(numMateriasStr, sizeof(numMateriasStr), stdin);
        numMateriasStr[strcspn(numMateriasStr, "\n")] = '\0';
        if (!validarNumero(numMateriasStr) || (numMaterias = atoi(numMateriasStr)) <= 0) {
            fprintf(stderr, "Error: no es un numero de materias valido\n");
        } else {
            break;
        }
    }

    char materia[MAX_STR_LEN];
    for (int i = 0; i < numMaterias; ++i) {
        printf("Materia %d: ", i + 1);
        fgets(materia, sizeof(materia), stdin);
        materia[strcspn(materia, "\n")] = '\0';
        agregarMateria(estudiante, materia);
    }

    printf("Datos del estudiante:\n");
    mostrarEstudiante(estudiante);
    mostrarMaterias(estudiante);

    return 0; // Indicate success
}

int registrarAsistencias(Estudiante* estudiante) {
    char fecha[MAX_STR_LEN], materia[MAX_STR_LEN], estado[MAX_STR_LEN];
    printf("Ingrese las asistencias (escriba 'fin' para terminar):\n");
    while (1) {
        printf("Fecha (YYYY-MM-DD): ");
        fgets(fecha, sizeof(fecha), stdin);
        fecha[strcspn(fecha, "\n")] = '\0';
        if (strcmp(fecha, "fin") == 0) break;
        if (!validarFecha(fecha)) {
            fprintf(stderr, "Error: %s no es una fecha valida\n", fecha);
            continue;
        }
        printf("Materia: ");
        fgets(materia, sizeof(materia), stdin);
        materia[strcspn(materia, "\n")] = '\0';
        printf("Estado (asistio/falta/tardanza): ");
        fgets(estado, sizeof(estado), stdin);
        estado[strcspn(estado, "\n")] = '\0';
        if (!validarEstado(estado)) {
            fprintf(stderr, "Estado incorrecto. Intente nuevamente.\n");
            continue;
        }
        registrarAsistencia(estudiante, fecha, materia, estado);
    }

    printf("Datos del estudiante despues de registrar asistencias:\n");
    mostrarAsistencias(estudiante);

    return 0; // Indicate success
}

int preguntarEliminarMateria(Estudiante* estudiante) {
    char respuesta[MAX_STR_LEN];
    printf("Quieres eliminar una materia? (si/no): ");
    fgets(respuesta, sizeof(respuesta), stdin);
    respuesta[strcspn(respuesta, "\n")] = '\0';

    if (strcmp(respuesta, "si") == 0) {
        char materia[MAX_STR_LEN];
        printf("Ingrese una materia para eliminar: ");
        fgets(materia, sizeof(materia), stdin);
        materia[strcspn(materia, "\n")] = '\0';
        eliminarMateria(estudiante, materia);

        printf("Datos del estudiante despues de eliminar la materia:\n");
        mostrarEstudiante(estudiante);
        mostrarMaterias(estudiante);
        mostrarAsistencias(estudiante);
    }

    return 0; // Indicate success
}