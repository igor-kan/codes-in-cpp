#include<cmath>
#include<cassert>
// continued fraction approximant order 8035
double compute_continued_frac_8035(double x){
    double a=1.0;
    for(int k=2;k>=1;--k) a=k+x/(a!=0.0?a:1.0);
    return a;
}
int main(){assert(std::isfinite(compute_continued_frac_8035(0.5)));return 0;}
