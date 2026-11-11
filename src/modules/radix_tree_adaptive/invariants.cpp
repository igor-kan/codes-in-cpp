/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#include <assert.h>
#include <math.h>

static inline void radix_tree_adaptive_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
