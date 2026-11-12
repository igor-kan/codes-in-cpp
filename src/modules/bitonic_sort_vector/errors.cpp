/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector
 */

typedef enum bitonic_sort_vector_error {
    BITONIC_SORT_VECTOR_SUCCESS = 0,
    BITONIC_SORT_VECTOR_ERR_INVALID_INPUT = -1,
    BITONIC_SORT_VECTOR_ERR_BUFFER_OVERFLOW = -2,
    BITONIC_SORT_VECTOR_ERR_CONVERGENCE_FAIL = -3
} bitonic_sort_vector_error_t;

const char* bitonic_sort_vector_str_error(bitonic_sort_vector_error_t code) {
    switch (code) {
        case BITONIC_SORT_VECTOR_SUCCESS: return "Operation completed successfully";
        case BITONIC_SORT_VECTOR_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case BITONIC_SORT_VECTOR_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case BITONIC_SORT_VECTOR_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
