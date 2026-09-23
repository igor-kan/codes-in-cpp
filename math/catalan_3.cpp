#include <cassert>
#include <iostream>

unsigned long long catalan(int n){ unsigned long long c=1; for(int k=1;k<=n;k++) c=c*2*(2*k-1)/(k+1); return c; }

int main() {
    assert((catalan(3)) == 5);
    std::cout << "PASS catalan_3\n";
    return 0;
}
