/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#include <stdint.h>

#define FAST_POLYNOMIAL_EVAL_BENCH_CYCLES 100000

typedef struct fast_polynomial_eval_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} fast_polynomial_eval_profile_results_t;
