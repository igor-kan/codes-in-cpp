#include "interface.hpp"

namespace codes_kosaraju_2sat_solver_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("kosaraju_2sat_solver_d57: problem size must be positive");
    }
}

} // namespace codes_kosaraju_2sat_solver_d57
