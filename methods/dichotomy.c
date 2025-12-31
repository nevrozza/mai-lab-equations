#include "methods.h"

double dichotomy_method(double (*f)(double), double a, double b, const double eps, int *iter) {
    if (f(a) * f(b) >= 0) {
        return NAN;
    }
    for (*iter = 0; (b - a) > eps; (*iter)++) {
        double m = (a + b) / 2.0;
        if (f(m) == 0.0) break;
        if (f(a) * f(m) < 0)
            b = m;
        else
            a = m;
    }
    return (a + b) / 2.0;
}

void run_dichotomy_method(double (*f)(double), double a, double b, const double eps) {
    printf("МЕТОД ДИХОТОМИИ\n");

    int iter;
    const double ans = dichotomy_method(f, a, b, eps, &iter);
    print_answer(f, ans, iter, "На концах отрезка одинаковые знаки! (корня нет!)");
    printf("\n");
}
