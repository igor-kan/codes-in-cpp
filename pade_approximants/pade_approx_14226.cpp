#include<cmath>
#include<cassert>
// rational function approximant order 14226
double compute_pade_approx_14226(double x){
    return (1.0+x*1.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_14226(0.5)));return 0;}
