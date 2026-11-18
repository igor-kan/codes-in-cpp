#include "interface.hpp"

namespace codes_fractional_cascading_grid {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("fractional_cascading_grid: problem size must be positive");
    }
}

} // namespace codes_fractional_cascading_grid
