/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#define KRYLOV_BICGSTAB_CACHE_LINE 64
#define KRYLOV_BICGSTAB_TILE_DIM 32

void krylov_bicgstab_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += KRYLOV_BICGSTAB_TILE_DIM) {
        size_t r_end = (r + KRYLOV_BICGSTAB_TILE_DIM < rows) ? r + KRYLOV_BICGSTAB_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
