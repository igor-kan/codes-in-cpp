#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_simulated_annealing_tsp;
    std::vector<Point2D> pts = {{0,0},{2,2},{2,0},{0,2},{1,0},{1,2}};
    auto best = parallel_best_restart(pts, 800);
    verify_valid_tour(6, best.tour);
    assert(best.total_length <= fast_tour_length(pts, {0,1,2,3,4,5}));
    return 0;
}
