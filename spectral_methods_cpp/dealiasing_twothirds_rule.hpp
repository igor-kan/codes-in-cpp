#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline bool is_aliased(int k, int N) { return std::abs(k) >= (N / 3); }
