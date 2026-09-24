#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double bicgstab_omega(double ts, double tt) { return ts / tt; }
