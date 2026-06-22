#include <stdio.h>
#include <stdlib.h> // Required for DMA functions

/*
 * C Foundations: Dynamic Memory Allocation (DMA)
 * Demonstrating malloc, calloc, realloc, and free on the Heap.
 */

int main() {
    printf("--- Test Case 1: malloc (Uninitialized Memory) ---\n");
    // Allocating memory for 3 integers
    int *arr_malloc = (int*)malloc(3 * sizeof(int));
    if (arr_malloc == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Writing data
    for (int i = 0; i < 3; i++) {
        arr_malloc[i] = i + 1; 
    }
    printf("[Success] Allocated 3 integers using malloc.\n");
    for (int i = 0; i < 3; i++) {
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }


    printf("\n--- Test Case 2: calloc (Zero-Initialized Memory) ---\n");
    // Allocating memory for 3 integers, initialized to 0
    int *arr_calloc = (int*)calloc(3, sizeof(int));
    if (arr_calloc == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("[Success] Allocated 3 integers using calloc.\n");
    // Printing to verify they are 0
    for (int i = 0; i < 3; i++) {
        printf("arr_calloc[%d] = %d (expected 0)\n", i, arr_calloc[i]);
    }


    printf("\n--- Test Case 3: realloc (Resizing Memory) ---\n");
    // Resizing the previous malloc block from 3 integers to 5 integers
    arr_malloc = (int*)realloc(arr_malloc, 5 * sizeof(int));
    if (arr_malloc == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    printf("[Success] Resized malloc array to 5 integers.\n");
    // Appending new data
    arr_malloc[3] = 40; 
    arr_malloc[4] = 50;
    for (int i = 0; i < 5; i++) {
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }


    printf("\n--- Test Case 4: free (Preventing Memory Leaks) ---\n");
    // Always free dynamically allocated memory once you're done with it!
    free(arr_malloc);
    free(arr_calloc);
    printf("[Success] Memory successfully freed. Heap is clean.\n");

    return 0;
}
