/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_csv_parser_sync_counter {
    volatile uint64_t count;
} simd_csv_parser_sync_counter_t;

static inline void simd_csv_parser_sync_inc_v47(simd_csv_parser_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
