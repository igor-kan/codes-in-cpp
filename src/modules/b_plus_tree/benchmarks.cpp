/**
 * Microbenchmark harness and cycle latency profiling for Cacheline-Sized Node B+ Tree for Ordered Storage.
 * Module: b_plus_tree
 */

#ifndef BENCH_B_PLUS_TREE_H
#define BENCH_B_PLUS_TREE_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct b_plus_tree_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} b_plus_tree_bench_metrics_t;

#endif /* BENCH_B_PLUS_TREE_H */
