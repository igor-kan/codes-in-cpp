#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(18)) == 5832);
    std::cout << "PASS cube_18\n";
    return 0;
}
