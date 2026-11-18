#include "interface.hpp"

namespace codes_palindromic_tree_eertree {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("palindromic_tree_eertree: problem size must be positive");
    }
}

} // namespace codes_palindromic_tree_eertree
