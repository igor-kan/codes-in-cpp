/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct sparse_dot_product_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} sparse_dot_product_atomic_state_t;

static inline void sparse_dot_product_atomic_increment(sparse_dot_product_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
