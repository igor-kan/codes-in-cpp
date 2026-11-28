#include "interface.hpp"

namespace codes_lfu_cache_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("lfu_cache_d61: problem size must be positive");
    }
}

} // namespace codes_lfu_cache_d61
