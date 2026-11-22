#include "interface.hpp"

namespace codes_suffix_array_doubling_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("suffix_array_doubling_d57: problem size must be positive");
    }
}

} // namespace codes_suffix_array_doubling_d57
