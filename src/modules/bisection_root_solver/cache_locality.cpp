/**
 * @file cache_locality.cpp
 * @brief Memory hierarchy alignment and cacheline optimizations for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#define BISECTION_ROOT_SOLVER_CACHELINE_SIZE 64
#define BISECTION_ROOT_SOLVER_BLOCK_SIZE 32

void bisection_root_solver_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += BISECTION_ROOT_SOLVER_BLOCK_SIZE) {
        size_t bi_end = (bi + BISECTION_ROOT_SOLVER_BLOCK_SIZE < n) ? (bi + BISECTION_ROOT_SOLVER_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += BISECTION_ROOT_SOLVER_BLOCK_SIZE) {
            size_t bj_end = (bj + BISECTION_ROOT_SOLVER_BLOCK_SIZE < n) ? (bj + BISECTION_ROOT_SOLVER_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
