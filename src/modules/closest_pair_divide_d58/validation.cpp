#include "interface.hpp"

namespace codes_closest_pair_divide_d58 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("closest_pair_divide_d58: problem size must be positive");
    }
}

} // namespace codes_closest_pair_divide_d58
