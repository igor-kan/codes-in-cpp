/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#include <stdint.h>

#define KRYLOV_BICGSTAB_BENCH_SAMPLES 100000

typedef struct krylov_bicgstab_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} krylov_bicgstab_bench_stats_t;
