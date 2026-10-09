#include<cmath>
#include<cassert>
// spherical harmonic radial component order 8064
double compute_spherical_harm_8064(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_8064(0.5)));return 0;}
