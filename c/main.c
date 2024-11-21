#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estudiantes.h"
#include "utils.h"
#include "excepciones.h"

int main() {
    Estudiante estudiante1;
    inicializarEstudiante(&estudiante1, "", 0, 0.0);

    if (solicitarDatosEstudiante(&estudiante1) != 0) {
        fprintf(stderr, "Error al solicitar datos del estudiante\n");
        return EXIT_FAILURE;
    }

    if (registrarAsistencias(&estudiante1) != 0) {
        fprintf(stderr, "Error al registrar asistencias\n");
        return EXIT_FAILURE;
    }

    if (preguntarEliminarMateria(&estudiante1) != 0) {
        fprintf(stderr, "Error al eliminar materia\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}