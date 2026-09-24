#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline bool ccw_straddle(double cp1, double cp2) { return (cp1 * cp2) <= 0.0; }
