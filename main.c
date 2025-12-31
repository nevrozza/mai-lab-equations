#include <float.h>

#include "solutions/solutions.h"
#include "common/common.h"


int main() {
    const double eps = DBL_EPSILON;
    const double a = 1.2, b = 2;

    const int convergence_steps_count = 100;
    const int max_iterations_count = 1000;

    setvbuf(stdout, NULL, _IONBF, 0);

    run_dichotomy_method(F, a, b, eps); // Без производных

    printf("\n=========== Аналитическое dF ===========\n");
    run_iterations_method(F, iter_F, d_iter_F_analytic, a, b, eps, convergence_steps_count, max_iterations_count);
    putchar('\n');
    run_newton_method(F, dF_analytic, ddF_analytic, a, b, eps, convergence_steps_count, max_iterations_count);

    printf("\n=========== Численное dF ===========\n");
    run_iterations_method(F, iter_F, d_iter_F_numeric, a, b, eps, convergence_steps_count, max_iterations_count);
    putchar('\n');
    run_newton_method(F, dF_numeric, ddF_numeric, a, b, eps, convergence_steps_count, max_iterations_count);
    return 0;
}
