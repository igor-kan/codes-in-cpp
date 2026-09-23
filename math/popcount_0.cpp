#include <cassert>
#include <iostream>

int popcount(unsigned long long n){ int c=0; while(n){ c+=n&1; n>>=1; } return c; }

int main() {
    assert((popcount(0ull)) == 0);
    std::cout << "PASS popcount_0\n";
    return 0;
}
