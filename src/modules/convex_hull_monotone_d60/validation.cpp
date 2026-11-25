#include "interface.hpp"

namespace codes_convex_hull_monotone_d60 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("convex_hull_monotone_d60: problem size must be positive");
    }
}

} // namespace codes_convex_hull_monotone_d60
