#include "common.h"


double F(const double x) {
    return x - 2 + sin(1.0 / x);
}

double dF_analytic(const double x) {
    return 1.0 - cos(1.0 / x) / (x * x);
}

double dF_numeric(const double x, const double step) {
    return (F(x + step) - F(x - step)) / (2.0);
}
