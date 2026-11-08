/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

typedef enum constexpr_radix_trie_error {
    CONSTEXPR_RADIX_TRIE_OK = 0,
    CONSTEXPR_RADIX_TRIE_ERR_NULL = -100,
    CONSTEXPR_RADIX_TRIE_ERR_CAPACITY = -101,
    CONSTEXPR_RADIX_TRIE_ERR_CONVERGENCE = -102
} constexpr_radix_trie_error_t;

const char* constexpr_radix_trie_strerror(constexpr_radix_trie_error_t err) {
    switch (err) {
        case CONSTEXPR_RADIX_TRIE_OK: return "Success";
        case CONSTEXPR_RADIX_TRIE_ERR_NULL: return "Encountered null pointer argument";
        case CONSTEXPR_RADIX_TRIE_ERR_CAPACITY: return "Capacity limit exceeded";
        case CONSTEXPR_RADIX_TRIE_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
