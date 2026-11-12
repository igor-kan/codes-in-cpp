/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics
 */

typedef enum quaternion_kinematics_error {
    QUATERNION_KINEMATICS_SUCCESS = 0,
    QUATERNION_KINEMATICS_ERR_INVALID_INPUT = -1,
    QUATERNION_KINEMATICS_ERR_BUFFER_OVERFLOW = -2,
    QUATERNION_KINEMATICS_ERR_CONVERGENCE_FAIL = -3
} quaternion_kinematics_error_t;

const char* quaternion_kinematics_str_error(quaternion_kinematics_error_t code) {
    switch (code) {
        case QUATERNION_KINEMATICS_SUCCESS: return "Operation completed successfully";
        case QUATERNION_KINEMATICS_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case QUATERNION_KINEMATICS_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case QUATERNION_KINEMATICS_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
