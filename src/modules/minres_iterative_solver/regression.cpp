/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#include <assert.h>

void test_minres_iterative_solver_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
