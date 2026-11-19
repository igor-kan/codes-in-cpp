#include "interface.hpp"

namespace codes_hungarian_min_assign_cpp {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("hungarian_min_assign_cpp: problem size must be positive");
    }
}

} // namespace codes_hungarian_min_assign_cpp
