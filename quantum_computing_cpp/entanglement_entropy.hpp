#pragma once
#include <cmath>
#include <vector>

inline double von_neumann_entropy_bipartite(double lambda1, double lambda2) {
    double s = 0.0;
    if (lambda1 > 1e-12) s -= lambda1 * std::log2(lambda1);
    if (lambda2 > 1e-12) s -= lambda2 * std::log2(lambda2);
    return s;
}
