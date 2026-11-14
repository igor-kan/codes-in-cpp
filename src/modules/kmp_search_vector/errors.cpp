/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector
 */

typedef enum kmp_search_vector_error_status {
    KMP_SEARCH_VECTOR_OK = 0,
    KMP_SEARCH_VECTOR_ERR_INVALID_PARAM = -10,
    KMP_SEARCH_VECTOR_ERR_CAPACITY_LIMIT = -11,
    KMP_SEARCH_VECTOR_ERR_NUMERICAL_FAULT = -12
} kmp_search_vector_error_status_t;

const char* kmp_search_vector_error_string(kmp_search_vector_error_status_t err) {
    switch (err) {
        case KMP_SEARCH_VECTOR_OK: return "Operational success";
        case KMP_SEARCH_VECTOR_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case KMP_SEARCH_VECTOR_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case KMP_SEARCH_VECTOR_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
