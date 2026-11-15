#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_delaunay_bowyer_watson {
std::vector<double> parallel_mesh_areas(const std::vector<std::vector<Pt2>>& clouds) {
    std::vector<double> out(clouds.size(), 0.0);
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, clouds.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < clouds.size(); i += nt) {
                auto tris = bowyer_watson_triangulate(clouds[i]);
                out[i] = triangulation_total_area(clouds[i], tris);
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_delaunay_bowyer_watson
