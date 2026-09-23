#include <cassert>
#include <iostream>

unsigned long long fact(int n){ unsigned long long r=1; for(int i=2;i<=n;i++) r*=i; return r; }

int main() {
    assert((fact(20)) == 2432902008176640000);
    std::cout << "PASS fact_20\n";
    return 0;
}
