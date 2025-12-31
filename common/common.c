#include "common.h"
#define STEP 1e-6

double d_numeric(double (*f)(double), const double x, const double step) {
    return (f(x + step) - f(x - step)) / (2.0 * step);
}

double F(const double x) {
    return (x == 0.0) ? NAN : x - 2 + sin(1.0 / x);
}

double dF_analytic(const double x) {
    return (x == 0.0) ? NAN : 1.0 - cos(1.0 / x) / (x * x);
}

double dF_numeric(const double x) {
    return d_numeric(F, x, STEP);
}

double ddF_analytic(const double x) {
    return (x == 0.0) ? NAN : (2 * x * cos(1.0 / x) - sin(1.0 / x)) / pow(x, 4);
}

double ddF_numeric(const double x) {
    return d_numeric(dF_numeric, x, STEP);
}


double iter_F(const double x) {
    return (x == 0.0) ? NAN : 2.0 - sin(1.0 / x);
}

double d_iter_F_analytic(const double x) {
    return (x == 0.0) ? NAN : -cos(1.0 / x) / (x * x);
}

double d_iter_F_numeric(const double x) {
    return d_numeric(iter_F, x, STEP);
}
