/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct chebyshev_nodes_gen_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} chebyshev_nodes_gen_sync_state_t;

static inline void chebyshev_nodes_gen_sync_increment(chebyshev_nodes_gen_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
