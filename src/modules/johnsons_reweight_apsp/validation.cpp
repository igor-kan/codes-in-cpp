#include "interface.hpp"

namespace codes_johnsons_reweight_apsp {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("johnsons_reweight_apsp: problem size must be positive");
    }
}

} // namespace codes_johnsons_reweight_apsp
