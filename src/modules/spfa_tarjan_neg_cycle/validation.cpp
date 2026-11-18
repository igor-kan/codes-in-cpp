#include "interface.hpp"

namespace codes_spfa_tarjan_neg_cycle {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("spfa_tarjan_neg_cycle: problem size must be positive");
    }
}

} // namespace codes_spfa_tarjan_neg_cycle
