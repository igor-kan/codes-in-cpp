#pragma once
#include <vector>
#include <cmath>
#include <iostream>

inline double laguerre_l(int n, double x) { if (n==0) return 1.0; if (n==1) return 1.0 - x; double l0=1.0, l1=1.0-x, l2=0.0; for(int i=2; i<=n; ++i) { l2 = ((2*i-1-x)*l1 - (i-1)*l0)/i; l0 = l1; l1 = l2; } return l1; }
