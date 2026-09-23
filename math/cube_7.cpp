#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(7)) == 343);
    std::cout << "PASS cube_7\n";
    return 0;
}
