#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double soft_threshold(double s, double tau) { return (s > tau)? s - tau : ((s < -tau)? s + tau : 0.0); }
