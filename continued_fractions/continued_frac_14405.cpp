#include<cmath>
#include<cassert>
// continued fraction approximant order 14405
double compute_continued_frac_14405(double x){
    double a=1.0;
    for(int k=6;k>=1;--k) a=k+x/(a!=0.0?a:1.0);
    return a;
}
int main(){assert(std::isfinite(compute_continued_frac_14405(0.5)));return 0;}
