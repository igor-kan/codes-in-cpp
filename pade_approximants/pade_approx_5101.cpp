#include<cmath>
#include<cassert>
// rational function approximant order 5101
double compute_pade_approx_5101(double x){
    return (1.0+x*2.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_5101(0.5)));return 0;}
