/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen
 */

#include <stdint.h>

#define CHEBYSHEV_NODES_GEN_BENCH_ITERATIONS 100000

typedef struct chebyshev_nodes_gen_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} chebyshev_nodes_gen_bench_metrics_t;
