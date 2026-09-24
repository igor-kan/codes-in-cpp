#pragma once
#include <vector>
#include <complex>

inline double depolarizing_fidelity(double p, double d = 2.0) {
    return 1.0 - p * (d - 1.0) / d;
}
