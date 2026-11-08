/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#ifndef KALMAN_FILTER_EIGEN_INTERFACE_H
#define KALMAN_FILTER_EIGEN_INTERFACE_H

#include "types.cpp"

typedef int (*kalman_filter_eigen_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct kalman_filter_eigen_interface {
    int (*init)(kalman_filter_eigen_state_t* state, const kalman_filter_eigen_config_t* cfg);
    int (*execute)(kalman_filter_eigen_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(kalman_filter_eigen_state_t* state);
    int (*destroy)(kalman_filter_eigen_state_t* state);
} kalman_filter_eigen_interface_t;

#endif /* KALMAN_FILTER_EIGEN_INTERFACE_H */
