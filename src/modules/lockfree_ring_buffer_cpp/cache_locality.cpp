/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#define LOCKFREE_RING_BUFFER_CPP_CACHE_LINE 64
#define LOCKFREE_RING_BUFFER_CPP_TILE_DIM 32

void lockfree_ring_buffer_cpp_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += LOCKFREE_RING_BUFFER_CPP_TILE_DIM) {
        size_t r_end = (r + LOCKFREE_RING_BUFFER_CPP_TILE_DIM < rows) ? r + LOCKFREE_RING_BUFFER_CPP_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
