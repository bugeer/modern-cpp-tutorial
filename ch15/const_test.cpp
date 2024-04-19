#include <array>

constexpr int sqr(int n) {
    return n*n;
}

int main (int argc, char *argv[]) {
    int a1[sqr(3)];

    int n = sqr(3);
    int a2[n];

    std::array<int, sqr(3)> a3;

    return 0;
}
