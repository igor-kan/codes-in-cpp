#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(100ull,75ull)) == 25);
    std::cout << "PASS gcd_100_75\n";
    return 0;
}
