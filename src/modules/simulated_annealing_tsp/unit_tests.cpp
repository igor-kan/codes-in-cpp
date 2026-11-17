#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_simulated_annealing_tsp;
    // Bowtie square ordering improved to perimeter length 4.0
    std::vector<Point2D> pts = {{0,0}, {1,1}, {1,0}, {0,1}};
    auto res = anneal_tsp_2opt(pts, 1000, 77ULL);
    verify_valid_tour(4, res.tour);
    assert(std::abs(res.total_length - 4.0) < 1e-6);
    return 0;
}
