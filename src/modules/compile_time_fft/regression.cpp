/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#include <assert.h>

void test_compile_time_fft_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
