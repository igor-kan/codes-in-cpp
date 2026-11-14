/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col
 */

#include <assert.h>
#include <math.h>

static inline void compressed_sparse_col_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
