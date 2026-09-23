#include <cassert>
#include <iostream>

unsigned long long fact(int n){ unsigned long long r=1; for(int i=2;i<=n;i++) r*=i; return r; }

int main() {
    assert((fact(16)) == 20922789888000);
    std::cout << "PASS fact_16\n";
    return 0;
}
