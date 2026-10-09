#include<cmath>
#include<cassert>
// fibonacci matrix power recurrence order 8068
double compute_fibonacci_matrix_8068(double x){
    double f0=1.0,f1=1.0;
    for(int i=0;i<5;++i){double nx=f0+f1*x*0.1;f0=f1;f1=nx;}
    return f1;
}
int main(){assert(std::isfinite(compute_fibonacci_matrix_8068(0.5)));return 0;}
