/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#include <stdint.h>

#define GMRES_ITERATIVE_SOLVER_BENCH_SAMPLES 100000

typedef struct gmres_iterative_solver_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} gmres_iterative_solver_bench_stats_t;
