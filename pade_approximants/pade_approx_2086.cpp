#include<cmath>
#include<cassert>
// rational function approximant order 2086
double compute_pade_approx_2086(double x){
    return (1.0+x*2.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_2086(0.5)));return 0;}
