/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct polynomial_interpolation_lagrange_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} polynomial_interpolation_lagrange_reentrant_lock_t;

static inline void polynomial_interpolation_lagrange_seq_advance(polynomial_interpolation_lagrange_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
