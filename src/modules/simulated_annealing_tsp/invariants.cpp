#include "interface.hpp"

namespace codes_simulated_annealing_tsp {
void verify_valid_tour(int n, const std::vector<int>& tour) {
    if (static_cast<int>(tour.size()) != n) throw std::logic_error("tour size mismatch");
    std::vector<bool> seen(static_cast<std::size_t>(n), false);
    for (int v : tour) {
        if (v < 0 || v >= n || seen[static_cast<std::size_t>(v)]) {
            throw std::logic_error("invalid permutation element in TSP tour");
        }
        seen[static_cast<std::size_t>(v)] = true;
    }
}
} // namespace codes_simulated_annealing_tsp
