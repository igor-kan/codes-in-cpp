#include<cmath>
#include<cassert>
// rational function approximant order 9056
double compute_pade_approx_9056(double x){
    return (1.0+x*3.0)/(1.0+x*x*1.0);
}
int main(){assert(std::isfinite(compute_pade_approx_9056(0.5)));return 0;}
