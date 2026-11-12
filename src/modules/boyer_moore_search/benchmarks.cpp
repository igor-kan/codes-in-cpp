/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Boyer-Moore Bad-Character Substring Locator.
 * Module: boyer_moore_search
 */

#include <stdint.h>

#define BOYER_MOORE_SEARCH_BENCH_CYCLES 100000

typedef struct boyer_moore_search_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} boyer_moore_search_profile_results_t;
