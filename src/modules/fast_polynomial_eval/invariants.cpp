/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#include <assert.h>
#include <math.h>

static inline void fast_polynomial_eval_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
