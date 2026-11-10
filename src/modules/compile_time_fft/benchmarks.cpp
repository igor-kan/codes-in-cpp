/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#include <stdint.h>

#define COMPILE_TIME_FFT_BENCH_SAMPLES 100000

typedef struct compile_time_fft_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} compile_time_fft_bench_stats_t;
