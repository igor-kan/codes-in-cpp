/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector
 */

#define BITONIC_SORT_VECTOR_CACHELINE_SIZE 64
#define BITONIC_SORT_VECTOR_BLOCK_SIZE 32

void bitonic_sort_vector_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += BITONIC_SORT_VECTOR_BLOCK_SIZE) {
        size_t bi_end = (bi + BITONIC_SORT_VECTOR_BLOCK_SIZE < n) ? (bi + BITONIC_SORT_VECTOR_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += BITONIC_SORT_VECTOR_BLOCK_SIZE) {
            size_t bj_end = (bj + BITONIC_SORT_VECTOR_BLOCK_SIZE < n) ? (bj + BITONIC_SORT_VECTOR_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
