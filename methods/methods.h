//
// Created by nevrozq on 31.12.2025.
//

#ifndef METHODS_H
#define METHODS_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "../common/common.h"

void run_iterations_method(double (*f)(double), double (*iter_f)(double), double (*d_iter_f)(double), double a,
                           double b, double eps, int convergence_steps_count,
                           int max_iterations_count);

void run_newton_method(double (*f)(double), double (*df)(double), double (*ddf)(double), double a, double b, double eps,
                       int convergence_steps_count, int max_iterations_count);

void run_dichotomy_method(double (*f)(double), double a, double b, double eps);


void run_all_methods(double (*f)(double), double (*iter_f)(double),
                     double (*df_analytic)(double), double (*df_numeric)(double),
                     double (*ddf_analytic)(double), double (*ddf_numeric)(double),
                     double (*d_iter_f_analytic)(double), double (*d_iter_f_numeric)(double),
                     double a, double b, double eps,
                     int convergence_steps_count, int max_iterations_count);


#endif //METHODS_H
