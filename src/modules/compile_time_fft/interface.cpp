/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#ifndef COMPILE_TIME_FFT_INTERFACE_H
#define COMPILE_TIME_FFT_INTERFACE_H

#include "types.cpp"

typedef int (*compile_time_fft_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct compile_time_fft_vtable {
    int (*init)(compile_time_fft_state_t* state, const compile_time_fft_config_t* cfg);
    int (*execute)(compile_time_fft_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(compile_time_fft_state_t* state);
    int (*destroy)(compile_time_fft_state_t* state);
} compile_time_fft_vtable_t;

#endif /* COMPILE_TIME_FFT_INTERFACE_H */
