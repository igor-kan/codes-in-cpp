#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double halton_base(int index, int base) { double f = 1.0, r = 0.0; while (index > 0) { f /= base; r += f * (index % base); index /= base; } return r; }
