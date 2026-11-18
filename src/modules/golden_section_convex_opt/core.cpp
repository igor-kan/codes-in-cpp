#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_golden_section_convex_opt {

Minima1D golden_section_minimize(RealFn1D f, double a, double b, double tol) {
    const double invphi = (std::sqrt(5.0) - 1.0) * 0.5;
    const double invphi2 = (3.0 - std::sqrt(5.0)) * 0.5;
    double h = b - a;
    int it = 0;
    double c = a + invphi2 * h, d = a + invphi * h;
    double yc = f(c), yd = f(d);
    while (h > tol && it < 200) {
        h *= invphi;
        if (yc < yd) {
            b = d; d = c; yd = yc;
            c = a + invphi2 * h; yc = f(c);
        } else {
            a = c; c = d; yc = yd;
            d = a + invphi * h; yd = f(d);
        }
        ++it;
    }
    double xm = 0.5 * (a + b);
    return {xm, f(xm), it};
}

} // namespace codes_golden_section_convex_opt
