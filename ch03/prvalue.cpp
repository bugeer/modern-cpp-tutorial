#include "../common/shape.h"
#include <cstdio>
#include <iostream>

class result {
public:
    result()  { puts("result()" ); }
    ~result() { puts("~result()"); }
};

result process_shape(const shape& shape1, const shape& shape2) {
    puts(__PRETTY_FUNCTION__);
    return result();
}

struct S {
    S(): m(42) {}
    S(int a): m(a) {}
    int m;
};

int main (int argc, char *argv[]) {
    puts(__PRETTY_FUNCTION__);
    // result && r = std::move(process_shape(circle(), triangle()));
    result && r = process_shape(circle(), triangle());
    puts("something else");

    std::cout << std::endl << std::endl;

    S s;
    std::cout << s.m << std::endl;

    s = S{};
    std::cout << s.m << std::endl;

    std::cout << (S{} = S{7}).m << std::endl;

    return 0;
}
