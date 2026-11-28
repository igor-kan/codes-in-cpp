#include "interface.hpp"

namespace codes_bron_kerbosch_clique_d61 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("bron_kerbosch_clique_d61: problem size must be positive");
    }
}

} // namespace codes_bron_kerbosch_clique_d61
