/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#include <assert.h>
#include <math.h>

static inline void simd_b_tree_node_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
