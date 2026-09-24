#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline int quad_quadrant(double x, double y, double cx, double cy) { return (x >= cx? 1 : 0) + (y >= cy? 2 : 0); }
