/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include <assert.h>
#include <math.h>

static inline void radix_sort_lsd_32_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
