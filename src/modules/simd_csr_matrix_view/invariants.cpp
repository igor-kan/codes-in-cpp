/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#include <assert.h>
#include <math.h>

static inline void simd_csr_matrix_view_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
