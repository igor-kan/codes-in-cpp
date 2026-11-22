#include "interface.hpp"

namespace codes_seg_tree_max_sub_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("seg_tree_max_sub_d57: problem size must be positive");
    }
}

} // namespace codes_seg_tree_max_sub_d57
