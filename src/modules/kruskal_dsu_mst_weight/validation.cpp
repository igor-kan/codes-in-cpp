#include "interface.hpp"

namespace codes_kruskal_dsu_mst_weight {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("kruskal_dsu_mst_weight: problem size must be positive");
    }
}

} // namespace codes_kruskal_dsu_mst_weight
