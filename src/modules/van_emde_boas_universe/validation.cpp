#include "interface.hpp"

namespace codes_van_emde_boas_universe {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("van_emde_boas_universe: problem size must be positive");
    }
}

} // namespace codes_van_emde_boas_universe
