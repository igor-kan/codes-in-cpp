/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct brent_dekker_root_solver_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} brent_dekker_root_solver_sync_state_t;

static inline void brent_dekker_root_solver_sync_increment(brent_dekker_root_solver_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
