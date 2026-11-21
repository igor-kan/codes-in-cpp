#include "interface.hpp"

namespace codes_floyd_warshall_min_cycle {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("floyd_warshall_min_cycle: problem size must be positive");
    }
}

} // namespace codes_floyd_warshall_min_cycle
