/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Boyer-Moore Bad-Character Substring Locator.
 * Module: boyer_moore_search
 */

typedef enum boyer_moore_search_error {
    BOYER_MOORE_SEARCH_SUCCESS = 0,
    BOYER_MOORE_SEARCH_ERR_INVALID_INPUT = -1,
    BOYER_MOORE_SEARCH_ERR_BUFFER_OVERFLOW = -2,
    BOYER_MOORE_SEARCH_ERR_CONVERGENCE_FAIL = -3
} boyer_moore_search_error_t;

const char* boyer_moore_search_str_error(boyer_moore_search_error_t code) {
    switch (code) {
        case BOYER_MOORE_SEARCH_SUCCESS: return "Operation completed successfully";
        case BOYER_MOORE_SEARCH_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case BOYER_MOORE_SEARCH_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case BOYER_MOORE_SEARCH_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
