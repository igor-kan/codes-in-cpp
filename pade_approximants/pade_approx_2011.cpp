#include<cmath>
#include<cassert>
// rational function approximant order 2011
double compute_pade_approx_2011(double x){
    return (1.0+x*2.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_2011(0.5)));return 0;}
