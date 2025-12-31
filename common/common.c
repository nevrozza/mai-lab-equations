#include "common.h"


double F(double x) {
    return x - 2 + sin(1.0 / x);
}

double dF_analytic(double x) {
    return 1.0 - cos(1.0 / x) / (x * x);
}

double dF_numeric(double x, double step) {
    return (F(x + step) - F(x - step)) / (2.0);
}
