#include <iostream>

// Quiz 3: What is the output of this program?
//         How would you write a specialization for count=0 ?

template <typename T, int count>
void loopIt(T x) {
    T val[count];
    for (int i=0; i<count; i++) {
        val[i] = x++;
        std::cout << val[i] << std::endl;
    }
}

// Look ./answers/quiz3-a.exclude

int main(int argc, char *argv[]) {
    float x = 2.1;
    loopIt<float,3>(x);

    return 0;
}