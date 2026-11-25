#include "interface.hpp"

namespace codes_kuhn_bipartite_match_d60 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("kuhn_bipartite_match_d60: problem size must be positive");
    }
}

} // namespace codes_kuhn_bipartite_match_d60
