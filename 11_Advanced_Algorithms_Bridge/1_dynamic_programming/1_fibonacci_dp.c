#include <stdio.h>

/*
 * Advanced: Dynamic Programming - Fibonacci
 * Demonstrates the massive speedup DP provides over pure recursion.
 */

#define MAX 100

// 1. Pure Recursion: O(2^N) - Extremely Slow
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 2. Top-Down DP (Memoization): O(N)
long long memo[MAX];
long long fibMemoization(int n) {
    if (n <= 1) return n;
    
    // Check if already calculated
    if (memo[n] != -1) return memo[n];
    
    // Calculate, save, and return
    memo[n] = fibMemoization(n - 1) + fibMemoization(n - 2);
    return memo[n];
}

// 3. Bottom-Up DP (Tabulation): O(N) Time, O(1) Space (Optimized)
long long fibTabulation(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0;
    long long prev1 = 1;
    long long curr;
    
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    printf("--- DP: Fibonacci Sequence Test Cases ---\n\n");
    
    // Initialize memoization array
    for (int i = 0; i < MAX; i++) memo[i] = -1;
    
    int n = 40; 
    
    printf("Calculating Fibonacci(%d)...\n", n);
    
    // Pure recursion will take a noticeable fraction of a second
    // printf("Recursive: %lld\n", fibRecursive(n)); // Uncomment to see how slow it is!
    
    printf("Memoization (Top-Down): %lld\n", fibMemoization(n));
    printf("Tabulation (Bottom-Up): %lld\n", fibTabulation(n));
    
    return 0;
}
