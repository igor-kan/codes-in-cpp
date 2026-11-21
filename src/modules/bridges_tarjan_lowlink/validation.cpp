#include "interface.hpp"

namespace codes_bridges_tarjan_lowlink {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("bridges_tarjan_lowlink: problem size must be positive");
    }
}

} // namespace codes_bridges_tarjan_lowlink
