#include <iostream>

// Quiz 1: What is the output of this program?
//         What is the effect of the "static" keyword on line 5?
//         What is the effect of volatile keyword?
//

static volatile int value = 100;

int foo(volatile int *value) {
    *value += 10; 
    return *value - 10;
}

void bar(int value) {
   value += 10;
}

int main(int argc, char *argv[]) {
    value += 10;
    std::cout << "Values : " << (bar(value), foo(&value)) << " : " << value << std::endl; 
    return 0;
}




