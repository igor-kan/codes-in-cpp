/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#define SIMD_B_TREE_NODE_CACHE_LINE 64
#define SIMD_B_TREE_NODE_TILE_DIM 32

void simd_b_tree_node_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SIMD_B_TREE_NODE_TILE_DIM) {
        size_t r_end = (r + SIMD_B_TREE_NODE_TILE_DIM < rows) ? r + SIMD_B_TREE_NODE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
