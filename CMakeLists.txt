cmake_minimum_required(VERSION 3.29)
project(Projet_info_Quoridor C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_info_Quoridor main.c
        sous_prog.c
        sous_prog.h
        pseudo.h
        pseudo.c)
