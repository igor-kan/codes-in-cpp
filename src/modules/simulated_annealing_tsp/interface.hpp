#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_simulated_annealing_tsp {
TspResult anneal_tsp_2opt(const std::vector<Point2D>& pts, int steps, std::uint64_t seed);
void validate_points(const std::vector<Point2D>& pts, int steps);
double fast_tour_length(const std::vector<Point2D>& pts, const std::vector<int>& tour);
TspResult parallel_best_restart(const std::vector<Point2D>& pts, int steps);
void verify_valid_tour(int n, const std::vector<int>& tour);
} // namespace codes_simulated_annealing_tsp
