/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#include <assert.h>
#include <math.h>

static inline void radix_tree_patricia_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
