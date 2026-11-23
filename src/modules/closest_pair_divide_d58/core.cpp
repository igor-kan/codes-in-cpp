#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_closest_pair_divide_d58 {

long long closest_pair_dist2(std::vector<std::pair<long long, long long>> pts) {
    if (pts.size() < 2) throw std::invalid_argument("at least two points required");
    std::sort(pts.begin(), pts.end());
    auto d2 = [](auto a, auto b) -> long long {
        long long dx = a.first - b.first, dy = a.second - b.second;
        return dx * dx + dy * dy;
    };
    auto solve = [&](auto& self, int l, int r) -> long long {
        if (r - l <= 3) {
            long long best = std::numeric_limits<long long>::max();
            for (int i = l; i < r; ++i)
                for (int j = i + 1; j < r; ++j) best = std::min(best, d2(pts[i], pts[j]));
            return best;
        }
        int mid = (l + r) / 2;
        long long midx = pts[mid].first;
        long long d = std::min(self(self, l, mid), self(self, mid, r));
        std::vector<std::pair<long long, long long>> strip;
        for (int i = l; i < r; ++i) {
            long long dx = pts[i].first - midx;
            if (dx * dx < d) strip.push_back(pts[i]);
        }
        std::sort(strip.begin(), strip.end(), [](auto a, auto b) { return a.second < b.second; });
        for (std::size_t i = 0; i < strip.size(); ++i) {
            for (std::size_t j = i + 1; j < strip.size(); ++j) {
                long long dy = strip[j].second - strip[i].second;
                if (dy * dy >= d) break;
                d = std::min(d, d2(strip[i], strip[j]));
            }
        }
        return d;
    };
    return solve(solve, 0, static_cast<int>(pts.size()));
}

} // namespace codes_closest_pair_divide_d58
