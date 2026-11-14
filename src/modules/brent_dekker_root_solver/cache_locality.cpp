/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver
 */

#define BRENT_DEKKER_ROOT_SOLVER_LINE_SZ 64
#define BRENT_DEKKER_ROOT_SOLVER_TILE_SZ 32

void brent_dekker_root_solver_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += BRENT_DEKKER_ROOT_SOLVER_TILE_SZ) {
        size_t r_max = (r + BRENT_DEKKER_ROOT_SOLVER_TILE_SZ < rows) ? (r + BRENT_DEKKER_ROOT_SOLVER_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
