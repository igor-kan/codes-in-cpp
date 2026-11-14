/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct compressed_sparse_col_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} compressed_sparse_col_sync_state_t;

static inline void compressed_sparse_col_sync_increment(compressed_sparse_col_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
