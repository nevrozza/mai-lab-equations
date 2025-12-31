#include "common.h"

double d_numeric(double (*f)(double), const double x, const double step) {
    return (f(x + step) - f(x - step)) / (2.0 * step);
}

void print_answer(double (*f)(double), const double ans, const int iter, char if_nan[]) {
    if (!isnan(ans)) {
        printf("Корень: %.10f (итераций: %d)\n", ans, iter);
        const double value = f(ans);
        printf("F(x) = %.15e", value);
    } else {
        printf("%s", if_nan);
    }
}

void print_iterations_answer(double (*f)(double), const double ans, const int iter, const int max_iterations_count) {
    char error_msg[80];
    snprintf(error_msg, sizeof(error_msg), "Метод не сошёлся за %d итераций", max_iterations_count);
    print_answer(f, ans, iter, error_msg);
}
