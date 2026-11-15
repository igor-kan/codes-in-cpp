#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <utility>

namespace codes_delaunay_bowyer_watson {
double tri_orient2d(Pt2 a, Pt2 b, Pt2 c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool point_in_circumcircle(Pt2 a, Pt2 b, Pt2 c, Pt2 d) {
    if (tri_orient2d(a, b, c) < 0.0) std::swap(b, c);
    double ax = a.x - d.x, ay = a.y - d.y;
    double bx = b.x - d.x, by = b.y - d.y;
    double cx = c.x - d.x, cy = c.y - d.y;
    double det = (ax * ax + ay * ay) * (bx * cy - cx * by)
               - (bx * bx + by * by) * (ax * cy - cx * ay)
               + (cx * cx + cy * cy) * (ax * by - bx * ay);
    return det > 1e-10;
}

std::vector<Tri> bowyer_watson_triangulate(const std::vector<Pt2>& points) {
    const std::size_t n = points.size();
    if (n < 3) return {};
    double minx = points[0].x, maxx = points[0].x;
    double miny = points[0].y, maxy = points[0].y;
    for (const auto& p : points) {
        minx = std::min(minx, p.x); maxx = std::max(maxx, p.x);
        miny = std::min(miny, p.y); maxy = std::max(maxy, p.y);
    }
    double dx = maxx - minx, dy = maxy - miny;
    double dmax = std::max({dx, dy, 1.0});
    double midx = (minx + maxx) * 0.5, midy = (miny + maxy) * 0.5;

    std::vector<Pt2> all = points;
    all.push_back({midx - 20.0 * dmax, midy - dmax});
    all.push_back({midx, midy + 20.0 * dmax});
    all.push_back({midx + 20.0 * dmax, midy - dmax});

    std::vector<Tri> tris = {{n, n + 1, n + 2}};
    for (std::size_t pi = 0; pi < n; ++pi) {
        std::vector<Tri> bad;
        std::vector<Tri> keep;
        for (const auto& t : tris) {
            if (point_in_circumcircle(all[t.a], all[t.b], all[t.c], all[pi])) bad.push_back(t);
            else keep.push_back(t);
        }
        std::vector<std::pair<std::size_t, std::size_t>> edges;
        for (const auto& t : bad) {
            edges.push_back({t.a, t.b});
            edges.push_back({t.b, t.c});
            edges.push_back({t.c, t.a});
        }
        std::vector<std::pair<std::size_t, std::size_t>> boundary;
        for (std::size_t i = 0; i < edges.size(); ++i) {
            bool shared = false;
            for (std::size_t j = 0; j < edges.size(); ++j) {
                if (i != j && ((edges[i].first == edges[j].second && edges[i].second == edges[j].first) ||
                               (edges[i].first == edges[j].first && edges[i].second == edges[j].second))) {
                    shared = true;
                    break;
                }
            }
            if (!shared) boundary.push_back(edges[i]);
        }
        tris = std::move(keep);
        for (const auto& e : boundary) {
            Tri nt{e.first, e.second, pi};
            if (tri_orient2d(all[nt.a], all[nt.b], all[nt.c]) < 0.0) std::swap(nt.a, nt.b);
            tris.push_back(nt);
        }
    }

    std::vector<Tri> res;
    for (const auto& t : tris) {
        if (t.a < n && t.b < n && t.c < n) res.push_back(t);
    }
    return res;
}
} // namespace codes_delaunay_bowyer_watson
