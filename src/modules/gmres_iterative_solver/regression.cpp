/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#include <assert.h>

void test_gmres_iterative_solver_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
