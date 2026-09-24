#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline int kd_split_axis(int depth, int k_dim) { return depth % k_dim; }
