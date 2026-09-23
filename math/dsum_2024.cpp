#include <cassert>
#include <iostream>

unsigned long long dsum(unsigned long long n){ unsigned long long s=0; while(n){ s+=n%10; n/=10; } return s; }

int main() {
    assert((dsum(2024ull)) == 8);
    std::cout << "PASS dsum_2024\n";
    return 0;
}
