#include <iostream>

// Quiz 1: What is the output of this program?

static int value = 100;

int foo(int *value) {
    *value += 10; 
    return *value;
}

void bar(int value) {
   value += 10;
}

int main(int argc, char *argv[]) {
    value += 10;
    std::cout << "Values : " << (bar(value), foo(&value)) << " : " << value << std::endl; 
    return 0;
} 

// Subquestions? 
// What is the effect of the "static" keyword on line 5?
