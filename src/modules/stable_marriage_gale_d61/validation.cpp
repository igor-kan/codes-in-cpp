#include "interface.hpp"

namespace codes_stable_marriage_gale_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("stable_marriage_gale_d61: problem size must be positive");
    }
}

} // namespace codes_stable_marriage_gale_d61
