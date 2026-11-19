#include "interface.hpp"

namespace codes_convex_hull_trick_deque {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("convex_hull_trick_deque: problem size must be positive");
    }
}

} // namespace codes_convex_hull_trick_deque
