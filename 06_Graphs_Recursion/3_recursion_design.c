#include <stdio.h>

/*
 * Recursion: Design of Recursive Algorithms & Tail Recursion
 */

// 1. Standard (Head/Non-Tail) Recursion
// The recursive call is NOT the last operation.
// E.g., Factorial: n * fact(n-1) -> multiplication happens AFTER recursion returns.
int factorial(int n) {
    if (n == 0 || n == 1) return 1; // Base case
    return n * factorial(n - 1);    // Recursive step
}

// 2. Tail Recursion
// The recursive call IS the absolute last operation.
// We use an "accumulator" to hold the running result.
// Modern compilers can optimize this to O(1) space instead of O(N) stack space.
int factorialTail(int n, int accumulator) {
    if (n == 0 || n == 1) return accumulator;
    return factorialTail(n - 1, n * accumulator);
}

// 3. When NOT to use recursion: Fibonacci
// This naive recursion takes O(2^N) time due to overlapping subproblems!
int badFibonacci(int n) {
    if (n <= 1) return n;
    return badFibonacci(n - 1) + badFibonacci(n - 2);
}

int main() {
    printf("--- Recursion Design Test Cases ---\n\n");
    
    printf("Test 1: Standard Factorial of 5 = %d\n", factorial(5));
    
    printf("Test 2: Tail Recursive Factorial of 5 = %d\n", factorialTail(5, 1));
    
    printf("\nTest 3: Bad Recursion (Fibonacci)\n");
    printf("Fibonacci of 10 = %d (Calculated redundantly)\n", badFibonacci(10));
    
    return 0;
}
