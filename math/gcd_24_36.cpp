#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(24ull,36ull)) == 12);
    std::cout << "PASS gcd_24_36\n";
    return 0;
}
