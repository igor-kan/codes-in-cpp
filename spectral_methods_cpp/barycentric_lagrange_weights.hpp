#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double cheb_weight(int j, int N) { double c = (j==0 || j==N)? 0.5 : 1.0; return (j % 2 == 0 ? 1.0 : -1.0) * c; }
