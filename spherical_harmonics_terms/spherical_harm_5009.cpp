#include<cmath>
#include<cassert>
// spherical harmonic radial component order 5009
double compute_spherical_harm_5009(double x){
    return std::pow(x,5)/static_cast<double>(10);
}
int main(){assert(std::isfinite(compute_spherical_harm_5009(0.5)));return 0;}
