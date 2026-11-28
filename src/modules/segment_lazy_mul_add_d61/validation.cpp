#include "interface.hpp"

namespace codes_segment_lazy_mul_add_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("segment_lazy_mul_add_d61: problem size must be positive");
    }
}

} // namespace codes_segment_lazy_mul_add_d61
