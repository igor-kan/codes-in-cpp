/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

#include <stdint.h>

#define SIMD_CSV_PARSER_BENCH_SAMPLES 100000

typedef struct simd_csv_parser_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_csv_parser_bench_stats_t;
