#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_half_plane_clipper {
std::vector<Vec2> intersect_half_planes(std::vector<HalfPlane> planes);
double polygon_area(const std::vector<Vec2>& poly);
Status validate_half_planes(const std::vector<HalfPlane>& planes);
bool point_inside_all(const std::vector<HalfPlane>& planes, Vec2 q, double eps);
std::vector<double> parallel_polygon_areas(const std::vector<std::vector<HalfPlane>>& batches);
Status verify_convex_left_region(const std::vector<HalfPlane>& planes, const std::vector<Vec2>& poly);
} // namespace codes_half_plane_clipper
