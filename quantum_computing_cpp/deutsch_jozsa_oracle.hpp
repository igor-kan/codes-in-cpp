#pragma once
#include <vector>
#include <cstdint>

inline bool evaluate_deutsch_jozsa_balanced(const std::vector<uint8_t>& oracle_truth_table) {
    size_t zeros = 0, ones = 0;
    for (uint8_t bit : oracle_truth_table) {
        if (bit == 0) zeros++; else ones++;
    }
    return (zeros == ones);
}
