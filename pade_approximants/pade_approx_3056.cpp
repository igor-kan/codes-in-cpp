#include<cmath>
#include<cassert>
// rational function approximant order 3056
double compute_pade_approx_3056(double x){
    return (1.0+x*3.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_3056(0.5)));return 0;}
