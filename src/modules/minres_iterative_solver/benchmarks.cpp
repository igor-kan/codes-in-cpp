/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#include <stdint.h>

#define MINRES_ITERATIVE_SOLVER_BENCH_SAMPLES 100000

typedef struct minres_iterative_solver_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} minres_iterative_solver_bench_stats_t;
