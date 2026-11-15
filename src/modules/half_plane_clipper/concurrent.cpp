#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_half_plane_clipper {
std::vector<double> parallel_polygon_areas(const std::vector<std::vector<HalfPlane>>& batches) {
    std::vector<double> out(batches.size(), 0.0);
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, batches.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < batches.size(); i += nt) {
                out[i] = polygon_area(intersect_half_planes(batches[i]));
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_half_plane_clipper
