/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#define DISCRETE_EVENT_SIM_CACHE_LINE 64
#define DISCRETE_EVENT_SIM_TILE_DIM 32

void discrete_event_sim_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += DISCRETE_EVENT_SIM_TILE_DIM) {
        size_t r_end = (r + DISCRETE_EVENT_SIM_TILE_DIM < rows) ? r + DISCRETE_EVENT_SIM_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
