#pragma once
#include <vector>

inline std::vector<double> apply_cnot_2qubit(const std::vector<double>& state) {
    return { state[0], state[1], state[3], state[2] };
}
