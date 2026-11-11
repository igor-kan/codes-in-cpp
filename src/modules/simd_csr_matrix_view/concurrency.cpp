/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_csr_matrix_view_sync_counter {
    volatile uint64_t count;
} simd_csr_matrix_view_sync_counter_t;

static inline void simd_csr_matrix_view_sync_inc_v47(simd_csr_matrix_view_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
