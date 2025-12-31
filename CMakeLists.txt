cmake_minimum_required(VERSION 4.0)
project(mai_lab_equation C)

set(CMAKE_C_STANDARD 17)

add_executable(mai_lab_equation
        main.c

        common/common.h
        common/common.c
        common/f1.c
        common/f2.c

        methods/methods.h
        methods/iterations.c
        methods/newton.c
        methods/dichotomy.c
        methods/all_methods.c)
