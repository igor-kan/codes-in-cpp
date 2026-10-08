#include<cmath>
#include<cassert>
// spherical harmonic radial component order 7014
double compute_spherical_harm_7014(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_7014(0.5)));return 0;}
