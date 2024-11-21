#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

typedef struct {
    char materia[50];
    char mensaje[100];
} MateriaNoEncontrada;

typedef struct {
    char fecha[11];
    char mensaje[100];
} FormatoFechaInvalido;

void inicializarMateriaNoEncontrada(MateriaNoEncontrada* error, const char* materia);
const char* obtenerMensajeMateriaNoEncontrada(const MateriaNoEncontrada* error);

void inicializarFormatoFechaInvalido(FormatoFechaInvalido* error, const char* fecha);
const char* obtenerMensajeFormatoFechaInvalido(const FormatoFechaInvalido* error);

#endif // EXCEPCIONES_H