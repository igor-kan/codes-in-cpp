#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double hermite_h(int n, double x) { if (n==0) return 1.0; if (n==1) return 2.0*x; double h0=1.0, h1=2.0*x, h2=0.0; for(int i=2; i<=n; ++i) { h2 = 2.0*x*h1 - 2.0*(i-1)*h0; h0 = h1; h1 = h2; } return h1; }
