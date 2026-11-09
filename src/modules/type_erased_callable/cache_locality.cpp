/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#define TYPE_ERASED_CALLABLE_CACHE_LINE 64
#define TYPE_ERASED_CALLABLE_TILE_DIM 32

void type_erased_callable_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += TYPE_ERASED_CALLABLE_TILE_DIM) {
        size_t r_end = (r + TYPE_ERASED_CALLABLE_TILE_DIM < rows) ? r + TYPE_ERASED_CALLABLE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
