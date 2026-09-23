#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(7ull,13ull)) == 1);
    std::cout << "PASS gcd_7_13\n";
    return 0;
}
