/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector
 */

#include <stdint.h>

#define BITONIC_SORT_VECTOR_BENCH_CYCLES 100000

typedef struct bitonic_sort_vector_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} bitonic_sort_vector_profile_results_t;
