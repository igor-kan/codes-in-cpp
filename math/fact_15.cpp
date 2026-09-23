#include <cassert>
#include <iostream>

unsigned long long fact(int n){ unsigned long long r=1; for(int i=2;i<=n;i++) r*=i; return r; }

int main() {
    assert((fact(15)) == 1307674368000);
    std::cout << "PASS fact_15\n";
    return 0;
}
