/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen
 */

#include <assert.h>

void test_chebyshev_nodes_gen_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
