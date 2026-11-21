#include "interface.hpp"

namespace codes_sos_dp_subset_convolution {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("sos_dp_subset_convolution: problem size must be positive");
    }
}

} // namespace codes_sos_dp_subset_convolution
