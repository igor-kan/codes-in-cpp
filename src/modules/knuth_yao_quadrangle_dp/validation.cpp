#include "interface.hpp"

namespace codes_knuth_yao_quadrangle_dp {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("knuth_yao_quadrangle_dp: problem size must be positive");
    }
}

} // namespace codes_knuth_yao_quadrangle_dp
