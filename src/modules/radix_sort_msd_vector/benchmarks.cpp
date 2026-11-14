/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

#include <stdint.h>

#define RADIX_SORT_MSD_VECTOR_BENCH_ITERATIONS 100000

typedef struct radix_sort_msd_vector_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} radix_sort_msd_vector_bench_metrics_t;
