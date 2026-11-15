#include "interface.hpp"
#include <cmath>

namespace codes_delaunay_bowyer_watson {
Status validate_points_distinct(const std::vector<Pt2>& pts) {
    if (pts.size() < 3) return Status::NullOrEmpty;
    for (std::size_t i = 0; i < pts.size(); ++i) {
        if (std::isnan(pts[i].x) || std::isnan(pts[i].y)) return Status::InvalidInput;
        for (std::size_t j = i + 1; j < pts.size(); ++j) {
            double dx = pts[i].x - pts[j].x, dy = pts[i].y - pts[j].y;
            if (dx * dx + dy * dy < 1e-18) return Status::InvalidInput;
        }
    }
    return Status::Ok;
}
} // namespace codes_delaunay_bowyer_watson
