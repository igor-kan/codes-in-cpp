#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double arithmetic_average(const std::vector<double>& s) { double sum = 0.0; for (double x : s) sum += x; return sum / s.size(); }
