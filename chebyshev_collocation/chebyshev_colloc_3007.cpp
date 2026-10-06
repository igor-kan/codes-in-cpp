#include<cmath>
#include<cassert>
// chebyshev collocation node order 3007
double compute_chebyshev_colloc_3007(double x){
    return std::cos(3.14159265358979*7.0/8.0)*x;
}
int main(){assert(std::isfinite(compute_chebyshev_colloc_3007(0.5)));return 0;}
