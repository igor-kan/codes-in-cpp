#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(48ull,60ull)) == 12);
    std::cout << "PASS gcd_48_60\n";
    return 0;
}
