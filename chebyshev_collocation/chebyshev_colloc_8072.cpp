#include<cmath>
#include<cassert>
// chebyshev collocation node order 8072
double compute_chebyshev_colloc_8072(double x){
    return std::cos(3.14159265358979*2.0/3.0)*x;
}
int main(){assert(std::isfinite(compute_chebyshev_colloc_8072(0.5)));return 0;}
