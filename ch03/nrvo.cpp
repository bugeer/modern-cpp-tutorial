#include <iostream>
#include <memory>
#include <utility>

class Obj{
public:
    Obj(             ) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Obj(const Obj&  o) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Obj(const Obj&& o) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

// may NRVO
Obj simple() {
    Obj obj;
    return obj;
}

// move makes no NRVO
Obj simple_with_move() {
    Obj obj;
    return std::move(obj);
}

// branch makes no NRVO
Obj complicated(int n) {
    Obj obj1;
    Obj obj2;

    if(n%2 == 0) {
        return obj1;
    } else {
        return obj2;
    }
}

int main (int argc, char *argv[]) {
    std::cout << "*** 1 ***" << std::endl;
    auto obj1 = simple();

    std::cout << "*** 2 ***" << std::endl;
    auto obj2 = simple_with_move();

    std::cout << "*** 3 ***" << std::endl;
    auto obj3 = complicated(42);

    std::cout << "*** 4 ***" << std::endl;
    auto obj4 = complicated(43);

    return 0;
}
