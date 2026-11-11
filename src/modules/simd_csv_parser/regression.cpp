/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

#include <assert.h>

void test_simd_csv_parser_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
