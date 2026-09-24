#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double sobol_van_der_corput(uint32_t n) { double q = 0.0, bk = 0.5; while (n > 0) { if (n & 1) q += bk; bk *= 0.5; n >>= 1; } return q; }
