/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct compile_time_matrix_exp_sync_counter {
    volatile uint64_t count;
} compile_time_matrix_exp_sync_counter_t;

static inline void compile_time_matrix_exp_sync_inc_v47(compile_time_matrix_exp_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
