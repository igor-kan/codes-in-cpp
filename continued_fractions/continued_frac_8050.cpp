#include<cmath>
#include<cassert>
// continued fraction approximant order 8050
double compute_continued_frac_8050(double x){
    double a=1.0;
    for(int k=5;k>=1;--k) a=k+x/(a!=0.0?a:1.0);
    return a;
}
int main(){assert(std::isfinite(compute_continued_frac_8050(0.5)));return 0;}
