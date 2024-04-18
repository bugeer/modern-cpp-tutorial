#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::string s0;
    std::cout << "b:" << *s0.begin()
        << ", f:" << s0.front()
        << ", b:" << s0.back()
        << ", e:" << *s0.end()
        << std::endl;

    s0 = "hello world!";
    std::cout
        << "b:"   << *s0.begin()
        << ", f:" << s0.front()
        << ", b:" << s0.back()
        << ", e:" << *s0.end()
        << std::endl;

    return 0;
}
