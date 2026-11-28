#include "interface.hpp"

namespace codes_bk_tree_metric_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("bk_tree_metric_d61: problem size must be positive");
    }
}

} // namespace codes_bk_tree_metric_d61
