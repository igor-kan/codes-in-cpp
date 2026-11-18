#include "interface.hpp"

namespace codes_scapegoat_weight_bst {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("scapegoat_weight_bst: problem size must be positive");
    }
}

} // namespace codes_scapegoat_weight_bst
