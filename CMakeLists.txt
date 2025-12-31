cmake_minimum_required(VERSION 4.0)
project(mai_lab_equation C)

set(CMAKE_C_STANDARD 17)

add_executable(mai_lab_equation
        main.c

        common/common.h
        common/common.c

        solutions/solutions.h
        solutions/iterations.c
        solutions/newton.c
        solutions/dichotomy.c)
