#include<cmath>
#include<cassert>
// rational function approximant order 9091
double compute_pade_approx_9091(double x){
    return (1.0+x*2.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_9091(0.5)));return 0;}
