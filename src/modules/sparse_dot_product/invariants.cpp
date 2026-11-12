/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product
 */

#include <assert.h>
#include <math.h>

static inline void sparse_dot_product_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
