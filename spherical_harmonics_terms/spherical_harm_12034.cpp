#include<cmath>
#include<cassert>
// spherical harmonic radial component order 12034
double compute_spherical_harm_12034(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_12034(0.5)));return 0;}
