#include "interface.hpp"

namespace codes_dinic_level_flow_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("dinic_level_flow_d57: problem size must be positive");
    }
}

} // namespace codes_dinic_level_flow_d57
