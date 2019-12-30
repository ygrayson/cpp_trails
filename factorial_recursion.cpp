#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

//Time Complexity: Linear O(n)
//Memory Complexity: Linear O(n)


int main() {
    int result;
    result = factorial(20);
    std::cout << result << std::endl;

    return 0;
}