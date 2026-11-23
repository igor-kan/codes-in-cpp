#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_graham_scan_hull_d58 {

long long convex_hull_area2(std::vector<std::pair<long long, long long>> pts) {
    if (pts.size() < 3) return 0;
    auto cross = [](auto o, auto a, auto b) -> long long {
        return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
    };
    std::sort(pts.begin(), pts.end());
    pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() < 3) return 0;
    std::vector<std::pair<long long, long long>> lo, hi;
    for (auto p : pts) {
        while (lo.size() >= 2 && cross(lo[lo.size() - 2], lo.back(), p) <= 0) lo.pop_back();
        lo.push_back(p);
    }
    for (int i = static_cast<int>(pts.size()) - 1; i >= 0; --i) {
        auto p = pts[i];
        while (hi.size() >= 2 && cross(hi[hi.size() - 2], hi.back(), p) <= 0) hi.pop_back();
        hi.push_back(p);
    }
    lo.pop_back(); hi.pop_back();
    lo.insert(lo.end(), hi.begin(), hi.end());
    long long area2 = 0;
    int m = static_cast<int>(lo.size());
    for (int i = 0; i < m; ++i) {
        auto a = lo[i];
        auto b = lo[(i + 1) % m];
        area2 += a.first * b.second - a.second * b.first;
    }
    return std::abs(area2);
}

} // namespace codes_graham_scan_hull_d58
