/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Boyer-Moore Bad-Character Substring Locator.
 * Module: boyer_moore_search
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct boyer_moore_search_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} boyer_moore_search_atomic_state_t;

static inline void boyer_moore_search_atomic_increment(boyer_moore_search_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
