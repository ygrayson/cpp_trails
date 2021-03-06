/* Fibonacci Problem
 * Dynammic Programming
 * Bottom-up solution
 */


#include <iostream>

#define MAX_LENGTH 10000
long unsigned int fib_arr[MAX_LENGTH] = {0, 1}; //initialize to all 0

long unsigned int fibonacci(int n) {
    // not computed yet: compute from bottom up
    if(fib_arr[n] == 0) {
        for(int i = 2; i < n+1; i++){
            fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
        }
    }
    return fib_arr[n];
}

//Time Complexity: Linear
//Memory Complexity: 


int main() {
    int result;
    result = fibonacci(40);
    std::cout << result << std::endl;

    return 0;
}