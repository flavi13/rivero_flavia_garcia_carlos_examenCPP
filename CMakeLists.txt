cmake_minimum_required(VERSION 3.10)

project(rivero_flavia_garcia_carlos_examenCPP)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)


add_executable(CPP
        cpp/main.cpp
        cpp/asistencia.cpp
        cpp/estudiantes.cpp
        cpp/excepciones.cpp
        cpp/utils.cpp
        cpp/estudiantes.h

)

add_executable(c
        c/main.c
        c/estudiantes.c
        c/estudiantes.h
        c/asistencia.c
        c/asistencia.h
        c/utils.c
        c/utils.h
        c/excepciones.c
        c/excepciones.h
)