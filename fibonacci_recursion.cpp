#include <iostream>

int fibonacci(int n) {
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

//Time Complexity: Exponential O()
//Memory Complexity: 


int main() {
    int result;
    result = fibonacci(40);
    std::cout << result << std::endl;

    return 0;
}