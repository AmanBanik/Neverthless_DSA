#include <stdio.h>

/*
 * Applied: Stacks - Next Greater Element
 * Find the next greater element for every element in an array.
 * 
 * Approach: Monotonic Decreasing Stack
 * We store indices in the stack. If the current element is greater than the element 
 * corresponding to the index at the top of the stack, we found the "Next Greater Element"
 * for the popped index.
 * Time: O(N), Space: O(N)
 */

void printNextGreater(int arr[], int n) {
    int stack[1000]; // Assuming small array for C testing
    int top = -1;
    int result[1000];
    
    // Initialize results array with -1
    for (int i = 0; i < n; i++) result[i] = -1;
    
    for (int i = 0; i < n; i++) {
        // While stack is not empty and current element is > element at stack top
        while (top != -1 && arr[i] > arr[stack[top]]) {
            int poppedIndex = stack[top--];
            result[poppedIndex] = arr[i];
        }
        stack[++top] = i; // Push current index
    }
    
    // Print the result
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
}

int main() {
    printf("--- Next Greater Element Test Cases ---\n\n");
    
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array: [4, 5, 2, 25]\n");
    printf("Results:\n");
    printNextGreater(arr, n);
    // Expected: 4->5, 5->25, 2->25, 25->-1
    
    return 0;
}
