#include "interface.hpp"

namespace codes_tarjan_lca_offline_d58 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("tarjan_lca_offline_d58: problem size must be positive");
    }
}

} // namespace codes_tarjan_lca_offline_d58
