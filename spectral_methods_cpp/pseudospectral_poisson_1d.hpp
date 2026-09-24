#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double poisson_eigenmode(int k, double L) { return - (k * M_PI / L) * (k * M_PI / L); }
