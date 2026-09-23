#include <cassert>
#include <iostream>

unsigned long long gcdv(unsigned long long a, unsigned long long b){ while(b){ auto t=a%b; a=b; b=t; } return a; }

int main() {
    assert((gcdv(81ull,27ull)) == 27);
    std::cout << "PASS gcd_81_27\n";
    return 0;
}
