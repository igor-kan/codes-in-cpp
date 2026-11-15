#include "interface.hpp"
#include <cmath>

namespace codes_half_plane_clipper {
Status validate_half_planes(const std::vector<HalfPlane>& planes) {
    if (planes.empty()) return Status::NullOrEmpty;
    for (const auto& hp : planes) {
        double len2 = hp.dir.x * hp.dir.x + hp.dir.y * hp.dir.y;
        if (len2 < 1e-24 || std::isnan(len2)) return Status::InvalidInput;
    }
    return Status::Ok;
}
} // namespace codes_half_plane_clipper
