#include <cstdlib>
#include <iostream>

class A {
public:
    A(         ) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    A(A &&     ) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    A(const A &) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A(        ) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

A getA_unnamed() {
    return A();
}

A getA_named() {
    return A();
}

A getA_duang() {
    A a1;
    A a2;

    if(rand() > 42) {
        // return std::move(a1);
        return a1;
    } else {
        // return std::move(a2);
        return a2;
    }
}

int main (int argc, char *argv[]) {
    std::cout << std::endl << "return unnamed:" << std::endl;
    auto a = getA_unnamed();
    std::cout << std::endl << "return named:"   << std::endl;
    auto b = getA_named();
    std::cout << std::endl << "return random:"  << std::endl;
    auto c = getA_duang();

    std::cout << std::endl << "ready to exit." << std::endl;

    return 0;
}
