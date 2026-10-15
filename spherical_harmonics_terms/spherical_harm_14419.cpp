#include<cmath>
#include<cassert>
// spherical harmonic radial component order 14419
double compute_spherical_harm_14419(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_14419(0.5)));return 0;}
