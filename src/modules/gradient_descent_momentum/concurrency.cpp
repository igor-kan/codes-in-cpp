/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct gradient_descent_momentum_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} gradient_descent_momentum_reentrant_lock_t;

static inline void gradient_descent_momentum_seq_advance(gradient_descent_momentum_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
