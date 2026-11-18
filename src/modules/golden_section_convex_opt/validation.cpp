#include "interface.hpp"

namespace codes_golden_section_convex_opt {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("golden_section_convex_opt: problem size must be positive");
    }
}

} // namespace codes_golden_section_convex_opt
