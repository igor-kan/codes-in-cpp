#include "interface.hpp"
#include <cmath>

namespace codes_simulated_annealing_tsp {
double fast_tour_length(const std::vector<Point2D>& pts, const std::vector<int>& tour) {
    double sum = 0.0;
    std::size_t n = tour.size();
    for (std::size_t i = 0; i < n; ++i) {
        const auto& a = pts[static_cast<std::size_t>(tour[i])];
        const auto& b = pts[static_cast<std::size_t>(tour[(i + 1) % n])];
        double dx = a.x - b.x, dy = a.y - b.y;
        sum += std::sqrt(dx * dx + dy * dy);
    }
    return sum;
}
} // namespace codes_simulated_annealing_tsp
