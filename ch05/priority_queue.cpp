#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include "../common/output_container.h"

int main (int argc, char *argv[]) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({1, 1});
    q.push({2, 2});
    q.push({0, 3});
    q.push({9, 4});

    while(!q.empty()) {
        std::cout << q.top() << std::endl;
        q.pop();
    }

    return 0;
}
