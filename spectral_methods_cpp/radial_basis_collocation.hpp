#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double gaussian_rbf(double r, double eps) { return std::exp(-(eps * r) * (eps * r)); }
