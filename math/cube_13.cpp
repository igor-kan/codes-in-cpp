#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(13)) == 2197);
    std::cout << "PASS cube_13\n";
    return 0;
}
