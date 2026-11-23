#include "interface.hpp"

namespace codes_treap_implicit_rev_d58 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("treap_implicit_rev_d58: problem size must be positive");
    }
}

} // namespace codes_treap_implicit_rev_d58
