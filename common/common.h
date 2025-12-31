#ifndef COMMON_H
#define COMMON_H
#include <math.h>
#include <stdio.h>
#define STEP 1e-6


double d_numeric(double (*f)(double), double x, double step);

double F1(double x);

double dF1_analytic(double x);

double dF1_numeric(double x);

double ddF1_analytic(double x);

double ddF1_numeric(double x);

double iter_F1(double x);

double d_iter_F1_analytic(double x);

double d_iter_F1_numeric(double x);


double F2(double x);

double dF2_analytic(double x);

double dF2_numeric(double x);

double ddF2_analytic(double x);

double ddF2_numeric(double x);

double iter_F2(double x);

double d_iter_F2_analytic(double x);

double d_iter_F2_numeric(double x);


void print_answer(double (*f)(double), double ans, int iter, char if_nan[]);

void print_iterations_answer(double (*f)(double), double ans, int iter, int max_iterations_count);

#endif //COMMON_H
