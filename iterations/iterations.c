#include "iterations.h"

double iter_F(const double x) {
    return 2.0 - sin(1.0 / x);
}

double d_iter_F_analytic(const double x) {
    return -cos(1.0 / x) / (x * x);
}

bool check_iter_convergence(double (*d_iter_f)(double), const double a, const double b, const int steps_count) {
    double max_abs = 0;
    double step = (b - a) / steps_count;
    for (int i = 0; i < steps_count; i++) {
        double x = a + step * i;
        max_abs = fmax(fabs(d_iter_f(x)), max_abs);
    }
    return max_abs < 1;
}

double iterations_method(double (*iter_f)(double), const double x0, const double eps, const int max_iter, int *iter) {
    double prev_x = x0;
    double cur_x = 0;
    for (*iter = 1; *iter <= max_iter; (*iter)++) {
        // считаем кол-во итераций
        cur_x = iter_f(prev_x);
        if (fabs(cur_x - prev_x) < eps) {
            return cur_x;
        }
        prev_x = cur_x;
    }

    // беда (не сошлось)
    return NAN;
}

void run_iterations_method(const double a, const double b, const double eps, const int convergence_steps_count,
                           const int max_iterations_count) {
    printf("МЕТОД ИТЕРАЦИЙ\n");
    if (check_iter_convergence(d_iter_F_analytic, a, b, convergence_steps_count)) {
        const double x0 = (a + b) / 2.0;
        int iter;
        const double ans = iterations_method(iter_F, x0, eps, max_iterations_count, &iter);
        if (!isnan(ans)) {
            printf("Корень: %.10f (итераций: %d)\n", ans, iter);
            const double value = fabs(F(ans));
            printf("Невязка: %.15e", value);
        } else {
            printf("Метод не сошелся за %d итераций", max_iterations_count);
        }
    } else {
        printf("Метод итераций не применим.");
    }
    printf("\n");
}
