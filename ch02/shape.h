#ifndef __SHAPE__
#define __SHAPE__

#include <cstdio>
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

inline
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

#endif // !__SHAPE__
