#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(12ull,18ull)) == 6);
    std::cout << "PASS gcd_12_18\n";
    return 0;
}
