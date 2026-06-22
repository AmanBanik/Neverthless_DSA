#include <stdio.h>

/*
 * C Foundations: Memory Layout & Variable Scope
 * This script demonstrates the difference between global, local, and static variables.
 */

// Global variables (Stored in Data Segment / BSS)
int global_var = 10;            // Initialized Data Segment
int uninit_global_var;          // BSS Segment (will be 0 by default)

void demonstrate_scope() {
    // Local variable (Stored in Stack) - destroyed after function exits
    int local_var = 20;
    
    // Static local variable (Stored in Data Segment) - persists across function calls
    static int static_local_var = 30; 
    
    printf("\nInside demonstrate_scope:\n");
    printf("  local_var (Stack) = %d\n", local_var);
    printf("  static_local_var (Data Segment) = %d\n", static_local_var);
    
    // Modify variables to observe changes in the next call
    local_var++;
    static_local_var++;
}

int main() {
    printf("--- Test Case 1: Global Variables ---\n");
    printf("Initialized Global var (Data Segment): %d\n", global_var);
    printf("Uninitialized Global var (BSS Segment): %d\n", uninit_global_var);
    
    printf("\n--- Test Case 2: Local vs Static Variables ---\n");
    printf("Calling function first time:");
    demonstrate_scope();
    
    printf("\nCalling function second time to observe static variable persistence:");
    demonstrate_scope(); 
    // Notice how 'local_var' resets to 20, but 'static_local_var' became 31
    
    return 0;
}
