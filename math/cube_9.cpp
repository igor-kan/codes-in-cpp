#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(9)) == 729);
    std::cout << "PASS cube_9\n";
    return 0;
}
