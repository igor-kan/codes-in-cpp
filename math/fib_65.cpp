#include <cassert>
#include <iostream>

unsigned long long fib(int n){ unsigned long long a=0,b=1,t; for(int i=0;i<n;i++){t=a+b;a=b;b=t;} return a; }

int main() {
    assert((fib(65)) == 17167680177565);
    std::cout << "PASS fib_65\n";
    return 0;
}
