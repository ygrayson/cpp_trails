/* Factorial Problem
 * Dynammic Programming
 * Bottom-up solution
 */

#include <iostream>

#define MAX_LENGTH 10000
long unsigned int fact_arr[MAX_LENGTH] = {0}; //initialize to all 0

long unsigned int factorial(int n) {
    // base case: 0!=1
    if (n == 0) {
        fact_arr[0] = 1;
        return 1;
    }
    // already computed
    else if (fact_arr[n] != 0) {
        return fact_arr[n];
    }
    // not computed yet
    else {
        fact_arr[0] = 1;
        for(int i = 1; i < n+1; i++){
            if(fact_arr[i] == 0){
                fact_arr[i] = i * fact_arr[i-1];
            }
        }
        return fact_arr[n];
    }
}

//Time Complexity: Linear O(n)
//Memory Complexity: Linear but bounded O(MAX_LENGTH)


int main() {
    long unsigned int result;
    result = factorial(5); //assume input is always smaller than MAX_LENGTH
    std::cout << result << std::endl;

    return 0;
}