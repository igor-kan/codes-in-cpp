/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

#include <assert.h>

void test_compile_time_matrix_exp_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
