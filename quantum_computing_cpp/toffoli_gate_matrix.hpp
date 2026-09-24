#pragma once
#include <vector>

inline std::vector<double> apply_toffoli_3qubit(std::vector<double> s) {
    std::swap(s[6], s[7]);
    return s;
}
