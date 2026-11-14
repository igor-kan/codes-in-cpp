/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver
 */

#include <stdint.h>

#define BRENT_DEKKER_ROOT_SOLVER_BENCH_ITERATIONS 100000

typedef struct brent_dekker_root_solver_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} brent_dekker_root_solver_bench_metrics_t;
