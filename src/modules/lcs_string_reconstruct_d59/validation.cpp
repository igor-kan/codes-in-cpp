#include "interface.hpp"

namespace codes_lcs_string_reconstruct_d59 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("lcs_string_reconstruct_d59: problem size must be positive");
    }
}

} // namespace codes_lcs_string_reconstruct_d59
