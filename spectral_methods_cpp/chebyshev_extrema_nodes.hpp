#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline std::vector<double> cheb_nodes(int N) { std::vector<double> x(N + 1); for(int j=0; j<=N; ++j) x[j] = std::cos(M_PI * j / N); return x; }
