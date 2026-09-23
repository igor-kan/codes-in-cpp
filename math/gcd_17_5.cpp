#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(17ull,5ull)) == 1);
    std::cout << "PASS gcd_17_5\n";
    return 0;
}
