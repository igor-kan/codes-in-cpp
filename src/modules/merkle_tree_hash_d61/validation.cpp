#include "interface.hpp"

namespace codes_merkle_tree_hash_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("merkle_tree_hash_d61: problem size must be positive");
    }
}

} // namespace codes_merkle_tree_hash_d61
