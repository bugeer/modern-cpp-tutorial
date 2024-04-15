#include <cstdio>
#include <utility>

enum class shape_type {
    circle,
    triangle,
    rectangle
};

class shape {
public:
    virtual ~shape() {
        puts("~shape");
    }
};

class circle : public shape {
public:
    ~circle() {
        puts("~circle");
    }
};

class triangle : public shape {
public:
    ~triangle() {
        puts("~triangle");
    }
};

class rectangle : public shape {
public:
    ~rectangle() {
        puts("~rectangle");
    }
};

shape* create_shape(shape_type type) {
    switch (type) {
        case shape_type::circle:
            return new circle();
        case shape_type::triangle:
            return new triangle();
        case shape_type::rectangle:
            return new rectangle();
        default:
            return new circle();
    }
}

template<typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr): ptr_(ptr) {
    }
    ~smart_ptr() {
        delete ptr_;
    }

    // smart_ptr(const smart_ptr&) = delete;
    // smart_ptr& operator=(const smart_ptr&) = delete;

    T* get() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }
    T& operator->() const {
        return ptr_;
    }
    operator bool() const {
        return ptr_;
    }

    smart_ptr(smart_ptr&& other) {
        ptr_ = other.release();
    }
    smart_ptr& operator=(smart_ptr rhs) {
        // smart_ptr(rhs).swap(*this);
        // return *this;
        rhs.swap(*this);
        return *this;
    }
    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }
    void swap(smart_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T *ptr_;
};

class shape_wrapper {
public:
    explicit shape_wrapper(shape* ptr = nullptr): ptr_(ptr) {
    }

    ~shape_wrapper() {
        delete ptr_;
    }

    shape* get() const {
        return ptr_;
    }

private:
    shape* ptr_;
};

int main (int argc, char *argv[]) {
    smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
    // smart_ptr<shape> ptr2{ptr1};
    smart_ptr<shape> ptr3;
    // ptr3 = ptr1;
    ptr3 = std::move(ptr1);
    smart_ptr<shape> ptr4{std::move(ptr3)};

    return 0;
}
