#include <iostream>
#include <string>
#include <utility>

int main (int argc, char *argv[]) {
    int source = 42;
    int destination = 21;
    std::cout << "&source:      " << &source      << std::endl;
    std::cout << "&destination: " << &destination << std::endl;

    destination = std::move(source);
    std::cout << "&source:      " << &source      << std::endl;
    std::cout << "&destination: " << &destination << std::endl;

    std::cout << source << std::endl;

    const std::string& rs = "hello";

    return 0;
}
