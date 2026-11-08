/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#include <assert.h>
#include <math.h>

static inline void sparse_matrix_csr_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
