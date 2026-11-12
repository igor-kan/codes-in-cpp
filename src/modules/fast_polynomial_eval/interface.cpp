/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval | Algorithm Family: polynomial
 */

#ifndef FAST_POLYNOMIAL_EVAL_INTERFACE_H
#define FAST_POLYNOMIAL_EVAL_INTERFACE_H

#include "types.cpp"

typedef int (*fast_polynomial_eval_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct fast_polynomial_eval_vtable {
    int (*init)(fast_polynomial_eval_state_t* state, const fast_polynomial_eval_config_t* cfg);
    int (*execute)(fast_polynomial_eval_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_polynomial_eval_state_t* state);
    int (*destroy)(fast_polynomial_eval_state_t* state);
} fast_polynomial_eval_vtable_t;

#endif /* FAST_POLYNOMIAL_EVAL_INTERFACE_H */
