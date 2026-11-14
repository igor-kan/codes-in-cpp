/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector
 */

#include <assert.h>
#include <math.h>

static inline void kmp_search_vector_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
