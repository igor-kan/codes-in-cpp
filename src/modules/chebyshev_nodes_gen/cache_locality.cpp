/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen
 */

#define CHEBYSHEV_NODES_GEN_LINE_SZ 64
#define CHEBYSHEV_NODES_GEN_TILE_SZ 32

void chebyshev_nodes_gen_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CHEBYSHEV_NODES_GEN_TILE_SZ) {
        size_t r_max = (r + CHEBYSHEV_NODES_GEN_TILE_SZ < rows) ? (r + CHEBYSHEV_NODES_GEN_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
