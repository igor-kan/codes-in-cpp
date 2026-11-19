#include "interface.hpp"

namespace codes_persistent_segtree_kth {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("persistent_segtree_kth: problem size must be positive");
    }
}

} // namespace codes_persistent_segtree_kth
