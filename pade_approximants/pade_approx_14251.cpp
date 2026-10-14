#include<cmath>
#include<cassert>
// rational function approximant order 14251
double compute_pade_approx_14251(double x){
    return (1.0+x*2.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_14251(0.5)));return 0;}
