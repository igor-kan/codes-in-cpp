/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Cacheline-Aligned Circular Deque with Modulo Wrap.
 * Module: deque_ring_buffer | Algorithm Family: ring_buffer
 */

#ifndef DEQUE_RING_BUFFER_INTERFACE_H
#define DEQUE_RING_BUFFER_INTERFACE_H

#include "types.cpp"

typedef int (*deque_ring_buffer_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct deque_ring_buffer_vtable {
    int (*init)(deque_ring_buffer_state_t* state, const deque_ring_buffer_config_t* cfg);
    int (*execute)(deque_ring_buffer_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(deque_ring_buffer_state_t* state);
    int (*destroy)(deque_ring_buffer_state_t* state);
} deque_ring_buffer_vtable_t;

#endif /* DEQUE_RING_BUFFER_INTERFACE_H */
