/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

typedef enum radix_sort_msd_vector_error_status {
    RADIX_SORT_MSD_VECTOR_OK = 0,
    RADIX_SORT_MSD_VECTOR_ERR_INVALID_PARAM = -10,
    RADIX_SORT_MSD_VECTOR_ERR_CAPACITY_LIMIT = -11,
    RADIX_SORT_MSD_VECTOR_ERR_NUMERICAL_FAULT = -12
} radix_sort_msd_vector_error_status_t;

const char* radix_sort_msd_vector_error_string(radix_sort_msd_vector_error_status_t err) {
    switch (err) {
        case RADIX_SORT_MSD_VECTOR_OK: return "Operational success";
        case RADIX_SORT_MSD_VECTOR_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case RADIX_SORT_MSD_VECTOR_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case RADIX_SORT_MSD_VECTOR_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
