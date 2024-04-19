#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

std::mutex output_lock;

void func(const char* name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> guard { output_lock };

    for(int i=0; i<100; ++i) {
        std::cout << "I am thread " << name << "\n";
    }
}

class scoped_thread {
public:
    template<typename... Arg> scoped_thread(Arg&&... arg): _thread(std::forward<Arg>(arg)...) {
    }
    scoped_thread(scoped_thread&& other): _thread(std::move(other)){
    }
    scoped_thread(const scoped_thread&  other) = delete;

    ~scoped_thread() {
        if (_thread.joinable()) {
            _thread.join();
        }
    }

private:
    std::thread _thread;
};

int main (int argc, char *argv[]) {
    // std::thread t1{func, "A"};
    // std::thread t2{func, "B"};

    // t1.join();
    // t2.join();

    scoped_thread t1{func, "A"};
    scoped_thread t2{func, "B"};

    return 0;
}
