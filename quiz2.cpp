#include <iostream>
#include <cstring>
#include <string>

// Quiz 2: Can you describe each of the 6 member functions of Foo?
//         What is the output of this program?
//         Why is the destructor made virtual?
//         What should happen (on a good compiler) if we remove the std::move()?
//  

class Foo {
private:
    uint8_t *mData;
    int mSize;
    std::string mName;
public:
    // 1
    Foo() : mName("Default") {
        std::cout << "Constructor "<< mName << std::endl;
    }

    // 2
    Foo(const uint8_t *data, int size, std::string name) : mSize(size), mName(name) {
        std::cout << "Constructor "<< mName << std::endl;
        mData = new uint8_t [size];
        std::memcpy(mData, data, size);
    }

    // 3
    virtual ~Foo() {
        std::cout << "Destructor " << mName << std::endl;
        if (mData) {
            delete []mData;
        }
    }

    // 4
    Foo(const Foo &x) : mSize(x.mSize), mName(x.mName) {
        std::cout << "Copy Constructor" << std::endl;
        mData = new uint8_t [x.mSize];
        std::memcpy(mData, x.mData, x.mSize);
    }

    // 5
    Foo(Foo &&x) {
        std::cout << "What is this member function called?" << std::endl;
        mData = x.mData;
        mSize = x.mSize;
        mName = x.mName;
        x.mData = (uint8_t *)0;        
    }

    // 6
    Foo &operator=(Foo x) {
        std::cout << "= Operator" << std::endl;
        std::swap(mData, x.mData);
        mSize = x.mSize;
        mName = x.mName;
        return *this;
    }

};

#define SIZE 8
const uint8_t *data = new uint8_t [SIZE];
const Foo gfoo{data, SIZE, std::string{"global"}};

Foo getAFoo() {
    return gfoo;
}

int main(int argc, char *argv[]) {

    Foo afoo{data, SIZE, std::string{"local"}};
    Foo bfoo = afoo;
    Foo cfoo(std::move(getAFoo()));
    // Foo cfoo(getAFoo());

    afoo = bfoo;

    delete []data;
    return 0;
}