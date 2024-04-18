#include <array>
#include <map>
#include <string>

// typedef char mykey_t[8];
typedef std::array<char, 8> mykey_t;

int main (int argc, char *argv[]) {
    std::map<mykey_t, int> mp;
    mykey_t mykey{"hello"};

    mp[mykey] = 42;

    std::map<std::string, int> mp1;
    std::string mykey1 = "hello";
    mp1[mykey1] = 42;

    return 0;
}
