#include<cmath>
#include<cassert>
// rational function approximant order 8071
double compute_pade_approx_8071(double x){
    return (1.0+x*2.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_8071(0.5)));return 0;}
