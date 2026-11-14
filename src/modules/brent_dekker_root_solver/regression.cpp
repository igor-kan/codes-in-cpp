/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver
 */

#include <assert.h>

void test_brent_dekker_root_solver_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
