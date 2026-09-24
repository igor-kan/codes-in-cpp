#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double ou_expectation(double x0, double theta, double mu, double t) { return mu + (x0 - mu) * std::exp(-theta * t); }
