/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector
 */

#include <stdint.h>

#define KMP_SEARCH_VECTOR_BENCH_ITERATIONS 100000

typedef struct kmp_search_vector_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} kmp_search_vector_bench_metrics_t;
