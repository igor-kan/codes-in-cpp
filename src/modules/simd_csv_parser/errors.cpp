/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

typedef enum simd_csv_parser_error_code {
    SIMD_CSV_PARSER_STATUS_OK = 0,
    SIMD_CSV_PARSER_ERR_NULL_PTR = -20,
    SIMD_CSV_PARSER_ERR_OUT_OF_BOUNDS = -21,
    SIMD_CSV_PARSER_ERR_DIVERGENCE = -22
} simd_csv_parser_error_code_t;

const char* simd_csv_parser_error_message(simd_csv_parser_error_code_t code) {
    switch (code) {
        case SIMD_CSV_PARSER_STATUS_OK: return "Operational success";
        case SIMD_CSV_PARSER_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_CSV_PARSER_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_CSV_PARSER_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
