#include "interface.hpp"
#include <thread>

namespace codes_simulated_annealing_tsp {
TspResult parallel_best_restart(const std::vector<Point2D>& pts, int steps) {
    TspResult r1, r2;
    std::thread t1([&]() { r1 = anneal_tsp_2opt(pts, steps, 101ULL); });
    std::thread t2([&]() { r2 = anneal_tsp_2opt(pts, steps, 202ULL); });
    t1.join();
    t2.join();
    return r1.total_length <= r2.total_length ? r1 : r2;
}
} // namespace codes_simulated_annealing_tsp
