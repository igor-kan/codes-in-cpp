/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_polynomial_eval_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} fast_polynomial_eval_atomic_state_t;

static inline void fast_polynomial_eval_atomic_increment(fast_polynomial_eval_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
