/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct compile_time_fft_sync_counter {
    volatile uint64_t count;
} compile_time_fft_sync_counter_t;

static inline void compile_time_fft_sync_inc(compile_time_fft_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
