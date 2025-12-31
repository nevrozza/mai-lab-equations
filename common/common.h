#ifndef COMMON_H
#define COMMON_H
#include <math.h>

double d_numeric(double (*f)(double), double x, double step);

double F(double x);

double dF_analytic(double x);
double dF_numeric(double x);

double ddF_analytic(double x);
double ddF_numeric(double x);

double iter_F(double x);

double d_iter_F_analytic(double x);
double d_iter_F_numeric(double x);

#endif //COMMON_H
