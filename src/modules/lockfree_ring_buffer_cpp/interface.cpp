/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#ifndef LOCKFREE_RING_BUFFER_CPP_INTERFACE_H
#define LOCKFREE_RING_BUFFER_CPP_INTERFACE_H

#include "types.cpp"

typedef int (*lockfree_ring_buffer_cpp_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_ring_buffer_cpp_vtable {
    int (*init)(lockfree_ring_buffer_cpp_state_t* state, const lockfree_ring_buffer_cpp_config_t* cfg);
    int (*execute)(lockfree_ring_buffer_cpp_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(lockfree_ring_buffer_cpp_state_t* state);
    int (*destroy)(lockfree_ring_buffer_cpp_state_t* state);
} lockfree_ring_buffer_cpp_vtable_t;

#endif /* LOCKFREE_RING_BUFFER_CPP_INTERFACE_H */
