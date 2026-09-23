#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(56ull,98ull)) == 14);
    std::cout << "PASS gcd_56_98\n";
    return 0;
}
