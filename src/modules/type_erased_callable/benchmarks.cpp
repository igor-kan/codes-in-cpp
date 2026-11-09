/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#include <stdint.h>

#define TYPE_ERASED_CALLABLE_BENCH_SAMPLES 100000

typedef struct type_erased_callable_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} type_erased_callable_bench_stats_t;
