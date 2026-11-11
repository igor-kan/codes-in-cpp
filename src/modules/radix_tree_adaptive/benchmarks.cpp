/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#include <stdint.h>

#define RADIX_TREE_ADAPTIVE_BENCH_SAMPLES 100000

typedef struct radix_tree_adaptive_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} radix_tree_adaptive_bench_stats_t;
