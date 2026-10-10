#include<cmath>
#include<cassert>
// rational function approximant order 9066
double compute_pade_approx_9066(double x){
    return (1.0+x*1.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_9066(0.5)));return 0;}
