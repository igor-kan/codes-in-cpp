#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>

namespace codes_simulated_annealing_tsp {

static double dist2(const Point2D& a, const Point2D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

static std::uint64_t lcg_next(std::uint64_t& st) {
    st = st * 6364136223846793005ULL + 1442695040888963407ULL;
    return st;
}

TspResult anneal_tsp_2opt(const std::vector<Point2D>& pts, int steps, std::uint64_t seed) {
    validate_points(pts, steps);
    int n = static_cast<int>(pts.size());
    std::vector<int> cur(static_cast<std::size_t>(n));
    std::iota(cur.begin(), cur.end(), 0);
    if (n <= 3) return {cur, fast_tour_length(pts, cur)};
    double cur_len = fast_tour_length(pts, cur);
    std::vector<int> best = cur;
    double best_len = cur_len;
    std::uint64_t rng = seed ? seed : 1ULL;
    double temp = 10.0;
    for (int s = 0; s < steps; ++s) {
        int i = static_cast<int>((lcg_next(rng) >> 32) % static_cast<std::uint64_t>(n));
        int j = static_cast<int>((lcg_next(rng) >> 32) % static_cast<std::uint64_t>(n));
        if (i == j) continue;
        if (i > j) std::swap(i, j);
        if (i == 0 && j == n - 1) continue;
        int prev_i = cur[static_cast<std::size_t>((i - 1 + n) % n)];
        int ci = cur[static_cast<std::size_t>(i)];
        int cj = cur[static_cast<std::size_t>(j)];
        int nxt_j = cur[static_cast<std::size_t>((j + 1) % n)];
        double before = dist2(pts[static_cast<std::size_t>(prev_i)], pts[static_cast<std::size_t>(ci)])
                      + dist2(pts[static_cast<std::size_t>(cj)], pts[static_cast<std::size_t>(nxt_j)]);
        double after = dist2(pts[static_cast<std::size_t>(prev_i)], pts[static_cast<std::size_t>(cj)])
                     + dist2(pts[static_cast<std::size_t>(ci)], pts[static_cast<std::size_t>(nxt_j)]);
        double delta = after - before;
        double u = static_cast<double>(lcg_next(rng) >> 11) / 9007199254740992.0;
        if (delta < 0.0 || u < std::exp(-delta / temp)) {
            std::reverse(cur.begin() + i, cur.begin() + j + 1);
            cur_len += delta;
            if (cur_len < best_len) {
                best_len = cur_len;
                best = cur;
            }
        }
        temp *= 0.995;
        if (temp < 1e-4) temp = 1e-4;
    }
    return {best, fast_tour_length(pts, best)};
}

} // namespace codes_simulated_annealing_tsp
