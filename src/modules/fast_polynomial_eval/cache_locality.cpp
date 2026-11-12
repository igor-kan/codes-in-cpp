/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#define FAST_POLYNOMIAL_EVAL_CACHELINE_SIZE 64
#define FAST_POLYNOMIAL_EVAL_BLOCK_SIZE 32

void fast_polynomial_eval_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += FAST_POLYNOMIAL_EVAL_BLOCK_SIZE) {
        size_t bi_end = (bi + FAST_POLYNOMIAL_EVAL_BLOCK_SIZE < n) ? (bi + FAST_POLYNOMIAL_EVAL_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += FAST_POLYNOMIAL_EVAL_BLOCK_SIZE) {
            size_t bj_end = (bj + FAST_POLYNOMIAL_EVAL_BLOCK_SIZE < n) ? (bj + FAST_POLYNOMIAL_EVAL_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
