/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum | Algorithm Family: optimization
 */

#ifndef GRADIENT_DESCENT_MOMENTUM_INTERFACE_H
#define GRADIENT_DESCENT_MOMENTUM_INTERFACE_H

#include "types.cpp"

typedef int (*gradient_descent_momentum_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct gradient_descent_momentum_vtable {
    int (*init)(gradient_descent_momentum_state_t* state, const gradient_descent_momentum_config_t* cfg);
    int (*execute)(gradient_descent_momentum_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(gradient_descent_momentum_state_t* state);
    int (*destroy)(gradient_descent_momentum_state_t* state);
} gradient_descent_momentum_vtable_t;

#endif /* GRADIENT_DESCENT_MOMENTUM_INTERFACE_H */
