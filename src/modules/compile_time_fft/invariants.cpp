/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#include <assert.h>
#include <math.h>

static inline void compile_time_fft_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
