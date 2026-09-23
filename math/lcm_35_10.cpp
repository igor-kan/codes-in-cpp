#include <cassert>
#include <iostream>

unsigned long long lcmv(unsigned long long a,unsigned long long b){ unsigned long long x=a,y=b,t; while(y){t=x%y;x=y;y=t;} return a/x*b; }

int main() {
    assert((lcmv(35ull,10ull)) == 70);
    std::cout << "PASS lcm_35_10\n";
    return 0;
}
