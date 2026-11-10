/**
 * @file types.cpp
 * @brief Core types and configuration for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

#ifndef COMPILE_TIME_FFT_TYPES_H
#define COMPILE_TIME_FFT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define COMPILE_TIME_FFT_ALIGNMENT 64
#define COMPILE_TIME_FFT_CAPACITY 4096

typedef struct compile_time_fft_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} compile_time_fft_config_t;

typedef struct compile_time_fft_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    compile_time_fft_config_t config;
} compile_time_fft_state_t;

#endif /* COMPILE_TIME_FFT_TYPES_H */
