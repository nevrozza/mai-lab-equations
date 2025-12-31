#include "common.h"

double F2(const double x) {
    return (x <= 0.0) ? NAN : exp(x) + log(x) - 10 * x;
}

double dF2_analytic(const double x) {
    return (x == 0.0) ? NAN : exp(x) + 1.0 / x - 10.0;
}

double dF2_numeric(const double x) {
    return d_numeric(F2, x, STEP);
}

double ddF2_analytic(const double x) {
    return (x == 0.0) ? NAN : exp(x) - 1.0 / (x * x);
}

double ddF2_numeric(const double x) {
    return d_numeric(dF2_numeric, x, STEP);
}


double iter_F2(const double x) {
    return (x <= 0.0) ? NAN : (exp(x) + log(x)) / 10;
}

double d_iter_F2_analytic(const double x) {
    return (x <= 0.0) ? NAN : (exp(x) + 1.0 / x) / 10;
}

double d_iter_F2_numeric(const double x) {
    return d_numeric(iter_F2, x, STEP);
}
