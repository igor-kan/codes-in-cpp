/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool simd_csr_matrix_view_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_csr_matrix_view_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
