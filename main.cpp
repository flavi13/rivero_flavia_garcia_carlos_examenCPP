#include <iostream>
#include "Estudiantes.h"
#include "utils.h"
#include "excepciones.h"

int main() {
    try {
        Estudiante estudiante1("", 0, 0.0);
        solicitarDatosEstudiante(estudiante1);
        registrarAsistencias(estudiante1);
        preguntarEliminarMateria(estudiante1);

    } catch (const MateriaNoEncontrada& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const FormatoFechaInvalido& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}