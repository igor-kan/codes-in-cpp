#include "interface.hpp"

namespace codes_kmp_cyclic_period_d59 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("kmp_cyclic_period_d59: problem size must be positive");
    }
}

} // namespace codes_kmp_cyclic_period_d59
