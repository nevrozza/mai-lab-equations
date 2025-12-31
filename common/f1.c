#include "common.h"

double F1(const double x) {
    return (x == 0.0) ? NAN : x - 2 + sin(1.0 / x);
}

double dF1_analytic(const double x) {
    return (x == 0.0) ? NAN : 1.0 - cos(1.0 / x) / (x * x);
}

double dF1_numeric(const double x) {
    return d_numeric(F1, x, STEP);
}

double ddF1_analytic(const double x) {
    return (x == 0.0) ? NAN : (2 * x * cos(1.0 / x) - sin(1.0 / x)) / pow(x, 4);
}

double ddF1_numeric(const double x) {
    return d_numeric(dF1_numeric, x, STEP);
}


double iter_F1(const double x) {
    return (x == 0.0) ? NAN : 2.0 - sin(1.0 / x);
}

double d_iter_F1_analytic(const double x) {
    return (x == 0.0) ? NAN : -cos(1.0 / x) / (x * x);
}

double d_iter_F1_numeric(const double x) {
    return d_numeric(iter_F1, x, STEP);
}