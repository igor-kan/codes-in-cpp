#include "interface.hpp"

namespace codes_monotonic_stack_histogram {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("monotonic_stack_histogram: problem size must be positive");
    }
}

} // namespace codes_monotonic_stack_histogram
