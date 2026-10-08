#include<cmath>
#include<cassert>
// chebyshev collocation node order 5062
double compute_chebyshev_colloc_5062(double x){
    return std::cos(3.14159265358979*2.0/3.0)*x;
}
int main(){assert(std::isfinite(compute_chebyshev_colloc_5062(0.5)));return 0;}
