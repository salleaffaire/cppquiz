#include <iostream>
#include <cstring>

// Quiz 2: What is the output of this program?
//         What is the Foo(Foo &&x) member function called?
//         Why is the destructor made virtual?
//         What should happen (on a good compiler) if we remove the std::move()?
//  

class Foo {
private:
    uint8_t *mData;
    int mSize;
public:
    Foo() {
        std::cout << "Constructor" << std::endl;
    }

    Foo(const uint8_t *data, int size) : mSize(size) {
        std::cout << "Constructor" << std::endl;
        mData = new uint8_t [size];
        std::memcpy(mData, data, size);
    }


    virtual ~Foo() {
        std::cout << "Destructor" << std::endl;
        if (mData) {
            delete []mData;
        }
    }

    Foo(const Foo &x) : mSize(x.mSize) {
        std::cout << "Copy Constructor" << std::endl;
        mData = new uint8_t [x.mSize];
        std::memcpy(mData, x.mData, x.mSize);
    }

    Foo(Foo &&x) {
        std::cout << "What is this member function called?" << std::endl;
        mData = x.mData;
        mSize = x.mSize;
        x.mData = (uint8_t *)0;        
    }

    Foo &operator=(Foo x) {
        std::cout << "= Operator" << std::endl;
        std::swap(mData, x.mData);
        mSize = x.mSize;
        return *this;
    }

};

#define SIZE 8
const uint8_t *data = new uint8_t [SIZE];
const Foo gfoo{data, SIZE};

Foo getAFoo() {
    return gfoo;
}

int main(int argc, char *argv[]) {

    Foo afoo{data, SIZE};
    Foo bfoo = afoo;
    Foo cfoo(std::move(getAFoo()));

    delete []data;
    return 0;
}