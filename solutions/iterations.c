#include "solutions.h"

bool check_iter_convergence(double (*d_iter_f)(double), const double a, const double b, const int steps_count) {
    double max_abs = 0;
    const double step = (b - a) / steps_count;
    for (int i = 0; i < steps_count; i++) {
        const double x = a + step * i;
        max_abs = fmax(fabs(d_iter_f(x)), max_abs);
    }
    return max_abs < 1;
}

double iterations_method(double (*iter_f)(double), const double x0, const double eps, const int max_iter, int *iter) {
    double prev_x = x0;
    // while, но +кол-во итераций
    for (*iter = 1; *iter <= max_iter; (*iter)++) {
        const double cur_x = iter_f(prev_x);
        if (fabs(cur_x - prev_x) < eps) {
            return cur_x;
        }
        prev_x = cur_x;
    }

    // беда (не сошлось)
    return NAN;
}

void run_iterations_method(double (*f)(double), double (*iter_f)(double), double (*d_iter_f)(double), const double a,
                           const double b, const double eps, const int convergence_steps_count,
                           const int max_iterations_count) {
    printf("МЕТОД ИТЕРАЦИЙ\n");
    if (check_iter_convergence(d_iter_f, a, b, convergence_steps_count)) {
        const double x0 = (a + b) / 2.0;
        int iter;
        const double ans = iterations_method(iter_f, x0, eps, max_iterations_count, &iter);
        print_iterations_answer(f, ans, iter, max_iterations_count);
    } else {
        printf("Метод итераций не применим");
    }
    printf("\n");
}
