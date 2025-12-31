//
// Created by nevrozq on 31.12.2025.
//

#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void run_iterations_method(double (*f)(double), double (*iter_f)(double), double (*d_iter_f)(double), double a,
                           double b, double eps, int convergence_steps_count,
                           int max_iterations_count);

void run_newton_method(double (*f)(double), double (*df)(double), double (*ddf)(double), double a, double b, double eps,
                       int convergence_steps_count, int max_iterations_count);

void run_dichotomy_method(double (*f)(double), double a, double b, double eps);


#endif //SOLUTIONS_H
