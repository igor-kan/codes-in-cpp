/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct minres_iterative_solver_sync_counter {
    volatile uint64_t count;
} minres_iterative_solver_sync_counter_t;

static inline void minres_iterative_solver_sync_inc_v47(minres_iterative_solver_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
