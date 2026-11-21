#include "interface.hpp"

namespace codes_eulerian_hierholzer_circuit {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("eulerian_hierholzer_circuit: problem size must be positive");
    }
}

} // namespace codes_eulerian_hierholzer_circuit
