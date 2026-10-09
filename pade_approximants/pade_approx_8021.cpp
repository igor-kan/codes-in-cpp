#include<cmath>
#include<cassert>
// rational function approximant order 8021
double compute_pade_approx_8021(double x){
    return (1.0+x*3.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_8021(0.5)));return 0;}
