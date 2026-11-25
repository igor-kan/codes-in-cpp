#include "interface.hpp"

namespace codes_z_algorithm_lcp_d60 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("z_algorithm_lcp_d60: problem size must be positive");
    }
}

} // namespace codes_z_algorithm_lcp_d60
