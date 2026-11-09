/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct type_erased_callable_sync_counter {
    volatile uint64_t count;
} type_erased_callable_sync_counter_t;

static inline void type_erased_callable_sync_inc(type_erased_callable_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
