/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#define COMPILE_TIME_FFT_CACHE_LINE 64
#define COMPILE_TIME_FFT_TILE_DIM 32

void compile_time_fft_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += COMPILE_TIME_FFT_TILE_DIM) {
        size_t r_end = (r + COMPILE_TIME_FFT_TILE_DIM < rows) ? r + COMPILE_TIME_FFT_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
