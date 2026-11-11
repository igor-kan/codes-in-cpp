/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#define ACTOR_FIBER_SCHEDULER_CACHE_LINE 64
#define ACTOR_FIBER_SCHEDULER_TILE_DIM 32

void actor_fiber_scheduler_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += ACTOR_FIBER_SCHEDULER_TILE_DIM) {
        size_t r_end = (r + ACTOR_FIBER_SCHEDULER_TILE_DIM < rows) ? r + ACTOR_FIBER_SCHEDULER_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
