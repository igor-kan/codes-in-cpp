#include "interface.hpp"

namespace codes_monotone_cht_env_d59 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("monotone_cht_env_d59: problem size must be positive");
    }
}

} // namespace codes_monotone_cht_env_d59
