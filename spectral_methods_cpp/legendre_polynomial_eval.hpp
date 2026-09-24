#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double legendre_p(int n, double x) { if (n==0) return 1.0; if (n==1) return x; double p0 = 1.0, p1 = x, p2 = 0.0; for(int i=2; i<=n; ++i) { p2 = ((2*i-1)*x*p1 - (i-1)*p0)/i; p0 = p1; p1 = p2; } return p1; }
