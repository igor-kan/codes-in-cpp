#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline int cube_sign_index(int mask, int bit) { return (mask >> bit) & 1; }
