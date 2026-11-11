/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

#include <stdint.h>

#define COMPILE_TIME_MATRIX_EXP_BENCH_SAMPLES 100000

typedef struct compile_time_matrix_exp_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} compile_time_matrix_exp_bench_stats_t;
