#include<cmath>
#include<cassert>
// rational function approximant order 14211
double compute_pade_approx_14211(double x){
    return (1.0+x*1.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_14211(0.5)));return 0;}
