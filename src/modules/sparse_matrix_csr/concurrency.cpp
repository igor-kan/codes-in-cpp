/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct sparse_matrix_csr_atomic_counter {
    volatile uint64_t value;
} sparse_matrix_csr_atomic_counter_t;

static inline void sparse_matrix_csr_counter_inc(sparse_matrix_csr_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
