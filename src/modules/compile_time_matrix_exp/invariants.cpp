/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

#include <assert.h>
#include <math.h>

static inline void compile_time_matrix_exp_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
