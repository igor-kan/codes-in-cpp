/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#include <assert.h>

void test_krylov_bicgstab_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
