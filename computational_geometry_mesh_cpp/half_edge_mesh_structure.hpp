#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline int twin_id(int e) { return (e % 2 == 0)? e + 1 : e - 1; }
