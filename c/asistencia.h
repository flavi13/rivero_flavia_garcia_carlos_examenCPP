#ifndef ASISTENCIA_H
#define ASISTENCIA_H

typedef struct {
    char fecha[11];
    char materia[50];
    char estado[20];
} Asistencia;

void inicializarAsistencia(Asistencia* asistencia, const char* fecha, const char* materia, const char* estado);
void mostrarAsistencia(const Asistencia* asistencia);
const char* getMateria(const Asistencia* asistencia);

#endif // ASISTENCIA_H