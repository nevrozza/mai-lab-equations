#include <float.h>

#include "methods.h"

bool check_newton_convergence(double (*f)(double), double (*df)(double), double (*ddf)(double), const double a,
                              const double b, const int steps_count) {
    const double step = (b - a) / steps_count;
    for (int i = 0; i < steps_count; i++) {
        const double x = a + step * i;
        const double d_v_value = df(x);
        if (fabs(f(x) * ddf(x)) >= (d_v_value * d_v_value)) {
            return false;
        }
    }
    return true;
}

double newton_method(double (*f)(double), double (*df)(double), const double x0, const double eps, const int max_iter,
                     int *iter) {
    double prev_x = x0;
    for (*iter = 1; *iter <= max_iter; (*iter)++) {
        const double cur_x = prev_x - f(prev_x) / df(prev_x);
        const double diff = fabs(cur_x - prev_x);
        const double residual = fabs(f(cur_x)); // невязка

        if (diff < eps || residual < DBL_EPSILON) {
            return cur_x;
        }

        prev_x = cur_x;
    }
    return NAN;
}

void run_newton_method(double (*f)(double), double (*df)(double), double (*ddf)(double), const double a, const double b, const double eps, const int convergence_steps_count,
                           const int max_iterations_count) {
    printf("МЕТОД НЬЮТОНА\n");
    // ctrl+c from iterations method...
    if (check_newton_convergence(f, df, ddf, a, b, convergence_steps_count)) {
        const double x0 = (a + b) / 2.0;
        int iter;
        const double ans = newton_method(f, df, x0, eps, max_iterations_count, &iter);
        print_iterations_answer(f, ans, iter, max_iterations_count);
    } else {
        printf("Метод Ньютона не применим");
    }
    printf("\n");
}
