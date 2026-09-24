#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double cross_product_2d(double ax, double ay, double bx, double by, double cx, double cy) { return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax); }
