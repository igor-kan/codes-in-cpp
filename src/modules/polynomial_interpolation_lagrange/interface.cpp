/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange | Algorithm Family: interpolation
 */

#ifndef POLYNOMIAL_INTERPOLATION_LAGRANGE_INTERFACE_H
#define POLYNOMIAL_INTERPOLATION_LAGRANGE_INTERFACE_H

#include "types.cpp"

typedef int (*polynomial_interpolation_lagrange_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct polynomial_interpolation_lagrange_vtable {
    int (*init)(polynomial_interpolation_lagrange_state_t* state, const polynomial_interpolation_lagrange_config_t* cfg);
    int (*execute)(polynomial_interpolation_lagrange_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(polynomial_interpolation_lagrange_state_t* state);
    int (*destroy)(polynomial_interpolation_lagrange_state_t* state);
} polynomial_interpolation_lagrange_vtable_t;

#endif /* POLYNOMIAL_INTERPOLATION_LAGRANGE_INTERFACE_H */
