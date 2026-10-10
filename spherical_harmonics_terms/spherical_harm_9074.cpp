#include<cmath>
#include<cassert>
// spherical harmonic radial component order 9074
double compute_spherical_harm_9074(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_9074(0.5)));return 0;}
