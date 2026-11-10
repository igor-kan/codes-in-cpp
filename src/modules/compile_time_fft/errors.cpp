/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Consteval Compile-Time Fast Fourier Transform Engine.
 * Module: compile_time_fft
 */

typedef enum compile_time_fft_error_code {
    COMPILE_TIME_FFT_STATUS_OK = 0,
    COMPILE_TIME_FFT_ERR_NULL_PTR = -10,
    COMPILE_TIME_FFT_ERR_OUT_OF_BOUNDS = -11,
    COMPILE_TIME_FFT_ERR_DIVERGENCE = -12
} compile_time_fft_error_code_t;

const char* compile_time_fft_error_message(compile_time_fft_error_code_t code) {
    switch (code) {
        case COMPILE_TIME_FFT_STATUS_OK: return "Operational success";
        case COMPILE_TIME_FFT_ERR_NULL_PTR: return "Null pointer argument";
        case COMPILE_TIME_FFT_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case COMPILE_TIME_FFT_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
