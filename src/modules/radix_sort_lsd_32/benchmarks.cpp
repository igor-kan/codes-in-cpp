/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include <stdint.h>

#define RADIX_SORT_LSD_32_BENCH_ITERATIONS 100000

typedef struct radix_sort_lsd_32_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} radix_sort_lsd_32_bench_metrics_t;
