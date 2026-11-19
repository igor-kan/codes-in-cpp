#include "interface.hpp"

namespace codes_tarjan_bridge_bcc_cpp {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("tarjan_bridge_bcc_cpp: problem size must be positive");
    }
}

} // namespace codes_tarjan_bridge_bcc_cpp
