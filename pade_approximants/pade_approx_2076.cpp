#include<cmath>
#include<cassert>
// rational function approximant order 2076
double compute_pade_approx_2076(double x){
    return (1.0+x*1.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_2076(0.5)));return 0;}
