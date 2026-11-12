/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bisection_root_solver_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} bisection_root_solver_atomic_state_t;

static inline void bisection_root_solver_atomic_increment(bisection_root_solver_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
