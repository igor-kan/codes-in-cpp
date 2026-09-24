#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double thomas_c_prime(double c, double b, double a, double c_prev) { return c / (b - a * c_prev); }
