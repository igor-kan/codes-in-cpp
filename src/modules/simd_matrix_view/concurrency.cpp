/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Padded 2D Strided Matrix View with Vectorization.
 * Module: simd_matrix_view
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_matrix_view_sync_counter {
    volatile uint64_t count;
} simd_matrix_view_sync_counter_t;

static inline void simd_matrix_view_sync_inc(simd_matrix_view_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
