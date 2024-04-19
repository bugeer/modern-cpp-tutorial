#include <iostream>
#include <stdexcept>

constexpr int fractorial(int n) {
    // static_assert(n >= 0, "n >= 0");
    if(n < 0) {
        throw std::invalid_argument("n >= 0");
    }

    if(n == 0) {
        return 1;
    } else {
        return n * fractorial(n-1);
    }
}

int main (int argc, char *argv[]) {
    constexpr int n = fractorial(10);
    // constexpr int m = fractorial(-1);

    std::cout << n << std::endl;

    return 0;
}
