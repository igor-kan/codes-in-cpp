/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product
 */

#define SPARSE_DOT_PRODUCT_CACHELINE_SIZE 64
#define SPARSE_DOT_PRODUCT_BLOCK_SIZE 32

void sparse_dot_product_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += SPARSE_DOT_PRODUCT_BLOCK_SIZE) {
        size_t bi_end = (bi + SPARSE_DOT_PRODUCT_BLOCK_SIZE < n) ? (bi + SPARSE_DOT_PRODUCT_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += SPARSE_DOT_PRODUCT_BLOCK_SIZE) {
            size_t bj_end = (bj + SPARSE_DOT_PRODUCT_BLOCK_SIZE < n) ? (bj + SPARSE_DOT_PRODUCT_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
