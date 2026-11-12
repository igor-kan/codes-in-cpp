/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#include <stdint.h>

#define BISECTION_ROOT_SOLVER_BENCH_CYCLES 100000

typedef struct bisection_root_solver_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} bisection_root_solver_profile_results_t;
