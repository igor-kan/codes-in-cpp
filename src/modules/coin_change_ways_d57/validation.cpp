#include "interface.hpp"

namespace codes_coin_change_ways_d57 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("coin_change_ways_d57: problem size must be positive");
    }
}

} // namespace codes_coin_change_ways_d57
