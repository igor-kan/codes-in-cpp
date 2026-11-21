#include "interface.hpp"

namespace codes_li_chao_convex_line_tree {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("li_chao_convex_line_tree: problem size must be positive");
    }
}

} // namespace codes_li_chao_convex_line_tree
