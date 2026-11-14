/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp
 */

typedef enum quaternion_slerp_cpp_error_status {
    QUATERNION_SLERP_CPP_OK = 0,
    QUATERNION_SLERP_CPP_ERR_INVALID_PARAM = -10,
    QUATERNION_SLERP_CPP_ERR_CAPACITY_LIMIT = -11,
    QUATERNION_SLERP_CPP_ERR_NUMERICAL_FAULT = -12
} quaternion_slerp_cpp_error_status_t;

const char* quaternion_slerp_cpp_error_string(quaternion_slerp_cpp_error_status_t err) {
    switch (err) {
        case QUATERNION_SLERP_CPP_OK: return "Operational success";
        case QUATERNION_SLERP_CPP_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case QUATERNION_SLERP_CPP_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case QUATERNION_SLERP_CPP_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
