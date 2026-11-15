#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <deque>

namespace codes_half_plane_clipper {
static double cross2(Vec2 a, Vec2 b) { return a.x * b.y - a.y * b.x; }
static Vec2 sub2(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }
static Vec2 add2(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
static Vec2 scale2(Vec2 a, double s) { return {a.x * s, a.y * s}; }

static bool is_outside(const HalfPlane& hp, Vec2 q) {
    return cross2(hp.dir, sub2(q, hp.p)) < -1e-11;
}

static Vec2 intersect_lines(const HalfPlane& a, const HalfPlane& b) {
    Vec2 u = sub2(a.p, b.p);
    double denom = cross2(a.dir, b.dir);
    double t = cross2(b.dir, u) / denom;
    return add2(a.p, scale2(a.dir, t));
}

std::vector<Vec2> intersect_half_planes(std::vector<HalfPlane> planes) {
    constexpr double B = 1e6;
    planes.push_back({{-B, -B}, {1.0, 0.0}});
    planes.push_back({{ B, -B}, {0.0, 1.0}});
    planes.push_back({{ B,  B}, {-1.0, 0.0}});
    planes.push_back({{-B,  B}, {0.0, -1.0}});

    auto angle_of = [](const HalfPlane& h) { return std::atan2(h.dir.y, h.dir.x); };
    std::sort(planes.begin(), planes.end(), [&](const HalfPlane& a, const HalfPlane& b) {
        double aa = angle_of(a), ab = angle_of(b);
        if (std::abs(aa - ab) > 1e-12) return aa < ab;
        return cross2(a.dir, sub2(b.p, a.p)) < 0.0;
    });

    std::vector<HalfPlane> uniq;
    uniq.reserve(planes.size());
    for (const auto& hp : planes) {
        if (uniq.empty() || std::abs(angle_of(uniq.back()) - angle_of(hp)) > 1e-12) {
            uniq.push_back(hp);
        }
    }

    std::deque<HalfPlane> dq;
    for (const auto& hp : uniq) {
        while (dq.size() >= 2) {
            Vec2 inter = intersect_lines(dq[dq.size() - 2], dq.back());
            if (is_outside(hp, inter)) dq.pop_back();
            else break;
        }
        while (dq.size() >= 2) {
            Vec2 inter = intersect_lines(dq[0], dq[1]);
            if (is_outside(hp, inter)) dq.pop_front();
            else break;
        }
        if (!dq.empty() && std::abs(cross2(dq.back().dir, hp.dir)) < 1e-12) {
            if (dq.back().dir.x * hp.dir.x + dq.back().dir.y * hp.dir.y < 0.0) {
                if (is_outside(hp, dq.back().p)) return {};
            }
        }
        dq.push_back(hp);
    }
    while (dq.size() >= 3) {
        Vec2 inter = intersect_lines(dq[dq.size() - 2], dq.back());
        if (is_outside(dq.front(), inter)) dq.pop_back();
        else break;
    }
    while (dq.size() >= 3) {
        Vec2 inter = intersect_lines(dq[0], dq[1]);
        if (is_outside(dq.back(), inter)) dq.pop_front();
        else break;
    }
    if (dq.size() < 3) return {};

    std::vector<Vec2> poly;
    poly.reserve(dq.size());
    for (std::size_t i = 0; i < dq.size(); ++i) {
        const auto& a = dq[i];
        const auto& b = dq[(i + 1) % dq.size()];
        if (std::abs(cross2(a.dir, b.dir)) < 1e-12) return {};
        Vec2 pt = intersect_lines(a, b);
        if (poly.empty() || std::hypot(pt.x - poly.back().x, pt.y - poly.back().y) > 1e-9) {
            poly.push_back(pt);
        }
    }
    if (poly.size() >= 2 && std::hypot(poly.front().x - poly.back().x, poly.front().y - poly.back().y) <= 1e-9) {
        poly.pop_back();
    }
    return poly;
}

double polygon_area(const std::vector<Vec2>& poly) {
    if (poly.size() < 3) return 0.0;
    double area2 = 0.0;
    for (std::size_t i = 0; i < poly.size(); ++i) {
        std::size_t j = (i + 1) % poly.size();
        area2 += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return 0.5 * area2;
}
} // namespace codes_half_plane_clipper
