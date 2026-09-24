#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline bool aabb_overlap(double minA, double maxA, double minB, double maxB) { return !(maxA < minB || maxB < minA); }
