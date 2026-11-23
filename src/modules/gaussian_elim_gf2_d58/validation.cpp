#include "interface.hpp"

namespace codes_gaussian_elim_gf2_d58 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("gaussian_elim_gf2_d58: problem size must be positive");
    }
}

} // namespace codes_gaussian_elim_gf2_d58
