#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double reflect_norm(double v0, double norm) { return v0 + (v0 >= 0 ? norm : -norm); }
