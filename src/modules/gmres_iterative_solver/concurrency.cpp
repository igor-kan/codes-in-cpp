/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct gmres_iterative_solver_sync_counter {
    volatile uint64_t count;
} gmres_iterative_solver_sync_counter_t;

static inline void gmres_iterative_solver_sync_inc(gmres_iterative_solver_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
