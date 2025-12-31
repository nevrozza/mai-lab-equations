#include <float.h>

#include "methods/methods.h"
#include "common/common.h"


int main() {
    const double eps = DBL_EPSILON;

    const int convergence_steps_count = 100;
    const int max_iterations_count = 1000;

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("----- x - 2 + sin (1/x) = 0 ----------------------------------------------------------\n\n");
    run_all_methods(F1, iter_F1,
                    dF1_analytic, dF1_numeric,
                    ddF1_analytic, ddF1_numeric,
                    d_iter_F1_analytic, d_iter_F1_numeric,
                    1.2, 2, eps, convergence_steps_count, max_iterations_count);

    printf("\n----- e^x - ln x - 10x = 0 -----------------------------------------------------------\n\n");
    run_all_methods(F2, iter_F2,
                    dF2_analytic, dF2_numeric,
                    ddF2_analytic, ddF2_numeric,
                    d_iter_F2_analytic, d_iter_F2_numeric,
                    3, 4, eps, convergence_steps_count, max_iterations_count);

    return 0;
}
