/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#ifndef TYPE_ERASED_CALLABLE_INTERFACE_H
#define TYPE_ERASED_CALLABLE_INTERFACE_H

#include "types.cpp"

typedef int (*type_erased_callable_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct type_erased_callable_vtable {
    int (*init)(type_erased_callable_state_t* state, const type_erased_callable_config_t* cfg);
    int (*execute)(type_erased_callable_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(type_erased_callable_state_t* state);
} type_erased_callable_vtable_t;

#endif /* TYPE_ERASED_CALLABLE_INTERFACE_H */
