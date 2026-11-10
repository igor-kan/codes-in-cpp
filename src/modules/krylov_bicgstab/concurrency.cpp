/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct krylov_bicgstab_sync_counter {
    volatile uint64_t count;
} krylov_bicgstab_sync_counter_t;

static inline void krylov_bicgstab_sync_inc(krylov_bicgstab_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
