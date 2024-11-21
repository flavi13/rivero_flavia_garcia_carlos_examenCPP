//
// Created by Flavia Rivero on 21/11/24.
//
#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
#include <string>

class MateriaNoEncontrada : public std::exception {
public:
    explicit MateriaNoEncontrada(const std::string& materia);
    const char* what() const noexcept override;
private:
    std::string materia;
    std::string mensaje;
};

class FormatoFechaInvalido : public std::exception {
public:
    explicit FormatoFechaInvalido(const std::string& fecha);
    const char* what() const noexcept override;
private:
    std::string fecha;
    std::string mensaje;
};

#endif // EXCEPCIONES_H