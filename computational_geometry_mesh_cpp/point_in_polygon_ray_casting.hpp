#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline bool ray_intersects_edge(double px, double py, double y1, double y2) { return (py > std::min(y1, y2)) && (py <= std::max(y1, y2)); }
