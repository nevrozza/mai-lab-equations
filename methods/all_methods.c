#include "methods.h"


void run_all_methods(double (*f)(double), double (*iter_f)(double),
                     double (*df_analytic)(double), double (*df_numeric)(double),
                     double (*ddf_analytic)(double), double (*ddf_numeric)(double),
                     double (*d_iter_f_analytic)(double), double (*d_iter_f_numeric)(double),
                     double a, double b, double eps,
                     int convergence_steps_count, int max_iterations_count) {
    run_dichotomy_method(f, a, b, eps); // Без производных

    printf("\n=========== Аналитическое dF ===========\n");
    run_iterations_method(f, iter_f, d_iter_f_analytic, a, b, eps, convergence_steps_count, max_iterations_count);
    putchar('\n');
    run_newton_method(f, df_analytic, ddf_analytic, a, b, eps, convergence_steps_count, max_iterations_count);

    printf("\n=========== Численное dF ===========\n");
    run_iterations_method(f, iter_f, d_iter_f_numeric, a, b, eps, convergence_steps_count, max_iterations_count);
    putchar('\n');
    run_newton_method(f, df_numeric, ddf_numeric, a, b, eps, convergence_steps_count, max_iterations_count);
}
