#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(35ull,15ull)) == 5);
    std::cout << "PASS gcd_35_15\n";
    return 0;
}
