/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#define MINRES_ITERATIVE_SOLVER_CACHE_LINE 64
#define MINRES_ITERATIVE_SOLVER_TILE_DIM 32

void minres_iterative_solver_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MINRES_ITERATIVE_SOLVER_TILE_DIM) {
        size_t r_end = (r + MINRES_ITERATIVE_SOLVER_TILE_DIM < rows) ? r + MINRES_ITERATIVE_SOLVER_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
