/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Cacheline-Aligned Circular Deque with Modulo Wrap.
 * Module: deque_ring_buffer
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct deque_ring_buffer_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} deque_ring_buffer_reentrant_lock_t;

static inline void deque_ring_buffer_seq_advance(deque_ring_buffer_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
