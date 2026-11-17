#include "interface.hpp"

namespace codes_heavy_light_euler_tour {
void validate_rooted_tree(int n, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init) {
    if (n <= 0 || static_cast<int>(edges.size()) != n - 1 || static_cast<int>(init.size()) != n) {
        throw std::invalid_argument("invalid tree size, edges, or initial node weights");
    }
}
} // namespace codes_heavy_light_euler_tour
