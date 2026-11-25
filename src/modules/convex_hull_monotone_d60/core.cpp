#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_convex_hull_monotone_d60 {

static std::int64_t cross_p(const Pt2D& o, const Pt2D& a, const Pt2D& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
std::vector<Pt2D> convex_hull_ccw(std::vector<Pt2D> pts) {
    std::sort(pts.begin(), pts.end());
    pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 2) return pts;
    std::vector<Pt2D> h;
    for (const auto& p : pts) {
        while (h.size() >= 2 && cross_p(h[h.size() - 2], h.back(), p) <= 0) h.pop_back();
        h.push_back(p);
    }
    std::size_t lower_sz = h.size();
    for (int i = static_cast<int>(pts.size()) - 2; i >= 0; --i) {
        while (h.size() > lower_sz && cross_p(h[h.size() - 2], h.back(), pts[i]) <= 0) h.pop_back();
        h.push_back(pts[i]);
    }
    h.pop_back();
    return h;
}
std::int64_t polygon_area2x(const std::vector<Pt2D>& poly) {
    std::int64_t a = 0;
    int n = static_cast<int>(poly.size());
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        a += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return a < 0 ? -a : a;
}

} // namespace codes_convex_hull_monotone_d60
