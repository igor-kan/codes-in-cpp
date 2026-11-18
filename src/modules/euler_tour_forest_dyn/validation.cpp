#include "interface.hpp"

namespace codes_euler_tour_forest_dyn {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("euler_tour_forest_dyn: problem size must be positive");
    }
}

} // namespace codes_euler_tour_forest_dyn
