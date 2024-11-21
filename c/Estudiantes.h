#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#define MAX_STR_LEN 100
#define MAX_MATERIAS 10
#define MAX_ASISTENCIAS 100

typedef struct {
    char fecha[MAX_STR_LEN];
    char materia[MAX_STR_LEN];
    char estado[MAX_STR_LEN];
} Asistencia;

typedef struct {
    char nombre[MAX_STR_LEN];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_STR_LEN];
    int numMaterias;
    Asistencia asistencias[MAX_ASISTENCIAS];
    int numAsistencias;
} Estudiante;

void inicializarEstudiante(Estudiante* estudiante, const char* nombre, int edad, float promedio);
void agregarMateria(Estudiante* estudiante, const char* materia);
void registrarAsistencia(Estudiante* estudiante, const char* fecha, const char* materia, const char* estado);
void mostrarEstudiante(const Estudiante* estudiante);
void mostrarMaterias(const Estudiante* estudiante);
void mostrarAsistencias(const Estudiante* estudiante);
void eliminarMateria(Estudiante* estudiante, const char* materia);
int validarFecha(const char* fecha);
int validarEstado(const char* estado);
void manejar_formato_fecha_invalido(const char* fecha);
void manejar_materia_no_encontrada(const char* materia);

#endif // ESTUDIANTES_H