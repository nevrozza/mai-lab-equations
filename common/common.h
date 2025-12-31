#ifndef COMMON_H
#define COMMON_H
#include <math.h>
#include <stdio.h>


double d_numeric(double (*f)(double), double x, double step);

double F(double x);

double dF_analytic(double x);

double dF_numeric(double x);

double ddF_analytic(double x);

double ddF_numeric(double x);

double iter_F(double x);

double d_iter_F_analytic(double x);

double d_iter_F_numeric(double x);


void print_answer(double (*f)(double), double ans, int iter, char if_nan[]);

void print_iterations_answer(double (*f)(double), double ans, int iter, int max_iterations_count);

#endif //COMMON_H
