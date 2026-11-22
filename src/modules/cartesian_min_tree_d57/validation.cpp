#include "interface.hpp"

namespace codes_cartesian_min_tree_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("cartesian_min_tree_d57: problem size must be positive");
    }
}

} // namespace codes_cartesian_min_tree_d57
