#include <float.h>

#include "solutions/solutions.h"


int main() {
    const double eps = DBL_EPSILON;
    const double a = 1.2, b = 2;

    // iterations method params
    const int convergence_steps_count = 100;
    const int max_iterations_count = 100;

    run_iterations_method(a, b, eps, convergence_steps_count, max_iterations_count);
    putchar('\n');
    run_dichotomy_method(a, b, eps);
    return 0;
}
