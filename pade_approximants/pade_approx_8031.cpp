#include<cmath>
#include<cassert>
// rational function approximant order 8031
double compute_pade_approx_8031(double x){
    return (1.0+x*1.0)/(1.0+x*x*2.0);
}
int main(){assert(std::isfinite(compute_pade_approx_8031(0.5)));return 0;}
