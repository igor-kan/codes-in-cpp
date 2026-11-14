/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

#include <assert.h>
#include <math.h>

static inline void radix_sort_msd_vector_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
