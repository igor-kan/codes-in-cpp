#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_delaunay_bowyer_watson {
std::vector<Tri> bowyer_watson_triangulate(const std::vector<Pt2>& points);
double tri_orient2d(Pt2 a, Pt2 b, Pt2 c);
bool point_in_circumcircle(Pt2 a, Pt2 b, Pt2 c, Pt2 d);
Status validate_points_distinct(const std::vector<Pt2>& pts);
double triangulation_total_area(const std::vector<Pt2>& pts, const std::vector<Tri>& tris);
std::vector<double> parallel_mesh_areas(const std::vector<std::vector<Pt2>>& clouds);
Status verify_empty_circumcircles(const std::vector<Pt2>& pts, const std::vector<Tri>& tris);
} // namespace codes_delaunay_bowyer_watson
