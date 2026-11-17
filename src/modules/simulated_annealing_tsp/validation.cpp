#include "interface.hpp"

namespace codes_simulated_annealing_tsp {
void validate_points(const std::vector<Point2D>& pts, int steps) {
    if (pts.empty() || steps <= 0) throw std::invalid_argument("points and step budget must be non-empty/positive");
}
} // namespace codes_simulated_annealing_tsp
