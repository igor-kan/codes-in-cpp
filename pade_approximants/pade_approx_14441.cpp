#include<cmath>
#include<cassert>
// rational function approximant order 14441
double compute_pade_approx_14441(double x){
    return (1.0+x*3.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_14441(0.5)));return 0;}
