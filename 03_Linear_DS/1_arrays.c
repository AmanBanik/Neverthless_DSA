#include <stdio.h>

#define MAX_SIZE 10

/*
 * Linear DS: Array Operations
 * Demonstrates Traversal, Insertion, and Deletion in an Array
 */

// Function to print array
void display(int arr[], int size) {
    printf("Array: [ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Inserts an element at a specific index
// Requires shifting elements to the right
int insert(int arr[], int *size, int element, int index) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array Overflow.\n");
        return -1;
    }
    if (index < 0 || index > *size) {
        printf("Error: Invalid Index.\n");
        return -1;
    }
    
    // Shift elements right
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;
    return 0;
}

// Deletes an element from a specific index
// Requires shifting elements to the left
int deleteElement(int arr[], int *size, int index) {
    if (*size <= 0) {
        printf("Error: Array Underflow.\n");
        return -1;
    }
    if (index < 0 || index >= *size) {
        printf("Error: Invalid Index.\n");
        return -1;
    }
    
    int deleted_val = arr[index];
    // Shift elements left
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return deleted_val;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40};
    int size = 4;
    
    printf("--- Array Operations Test Cases ---\n\n");
    
    printf("Test 1: Initial State\n");
    display(arr, size);
    
    printf("\nTest 2: Insert '25' at index 2\n");
    insert(arr, &size, 25, 2);
    display(arr, size);
    
    printf("\nTest 3: Insert '50' at end (index %d)\n", size);
    insert(arr, &size, 50, size);
    display(arr, size);
    
    printf("\nTest 4: Delete element at index 1 (value 20)\n");
    int del = deleteElement(arr, &size, 1);
    printf("Deleted value: %d\n", del);
    display(arr, size);

    printf("\nTest 5: Edge Case - Delete invalid index (10)\n");
    deleteElement(arr, &size, 10);
    
    return 0;
}
