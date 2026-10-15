#include<cmath>
#include<cassert>
// continued fraction approximant order 14475
double compute_continued_frac_14475(double x){
    double a=1.0;
    for(int k=4;k>=1;--k) a=k+x/(a!=0.0?a:1.0);
    return a;
}
int main(){assert(std::isfinite(compute_continued_frac_14475(0.5)));return 0;}
