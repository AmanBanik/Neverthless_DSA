#include <stdio.h>

/*
 * Hashing: Hash Function Implementations
 */

#define TABLE_SIZE 10

// 1. Division Method
// The simplest and most common. (Usually TableSize should be a prime number)
int hashDivision(int key) {
    return key % TABLE_SIZE;
}

// 2. Mid-Square Method (Simulated)
// Squares the key, extracts the middle digits
int hashMidSquare(int key) {
    long long squared = (long long)key * key;
    // For simplicity, let's just divide by 10 and mod by Table Size
    // to simulate extracting middle digits.
    return (squared / 10) % TABLE_SIZE;
}

// 3. Multiplication Method
// h(k) = floor( m * (k * A mod 1) )
// A is a constant like 0.618033 (Golden ratio)
int hashMultiplication(int key) {
    float A = 0.618033;
    float fractional_part = (key * A) - (int)(key * A); // k*A mod 1
    return (int)(TABLE_SIZE * fractional_part);
}

int main() {
    printf("--- Hash Functions Test Cases ---\n\n");
    
    int keys[] = {15, 27, 88, 104, 5};
    int n = sizeof(keys)/sizeof(keys[0]);
    
    printf("Table Size: %d\n\n", TABLE_SIZE);
    
    for (int i = 0; i < n; i++) {
        printf("Key: %-4d | Division: %-2d | Mid-Square: %-2d | Multiplication: %-2d\n",
               keys[i],
               hashDivision(keys[i]),
               hashMidSquare(keys[i]),
               hashMultiplication(keys[i]));
    }
    
    return 0;
}
