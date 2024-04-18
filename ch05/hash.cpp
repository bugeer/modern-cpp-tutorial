#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "../common/output_container.h"

int main (int argc, char *argv[]) {
    std::vector<int> v{13, 6, 4, 11, 39};
    std::cout << v << std::endl;

    std::sort(v.begin(), v.end());
    std::cout << v << std::endl;

    std::sort(v.begin(), v.end(), std::greater<int>());
    std::cout << v << std::endl;

    std::cout << std::hex;

    auto hp = std::hash<int*>();
    std::cout << "hash(nullptr) : " << hp(nullptr)  << std::endl;
    std::cout << "hash(v.data()): 0x" << hp(v.data()) << std::endl;
    std::cout << "v.data()      : " << static_cast<void*>(v.data()) << std::endl;

    auto hs = std::hash<std::string>();
    std::cout << "hash(\"hello\") : " << hs("hello") << std::endl;
    std::cout << "hash(\"hellp\") : " << hs("hellp") << std::endl;


    return 0;
}
