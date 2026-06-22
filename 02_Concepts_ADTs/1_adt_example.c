#include <stdio.h>
#include <stdlib.h>

/*
 * Abstract Data Type (ADT) Example
 * We are creating a custom "SmartArray" ADT.
 * It hides the complex array management (size vs capacity) from the user.
 */

// 1. Data Declaration (The "What")
typedef struct {
    int *data;
    int capacity;
    int size;
} SmartArray;

// 2. Operations Declaration (The "Functions")

// Constructor-like function
void initArray(SmartArray *arr, int cap) {
    arr->capacity = cap;
    arr->size = 0;
    arr->data = (int*)malloc(cap * sizeof(int));
}

// Operation: Insert
void insert(SmartArray *arr, int element) {
    if (arr->size >= arr->capacity) {
        printf("Error: Array is at full capacity (%d)!\n", arr->capacity);
        return;
    }
    arr->data[arr->size] = element;
    arr->size++;
    printf("Inserted: %d (Size is now %d)\n", element, arr->size);
}

// Operation: Display
void display(SmartArray *arr) {
    printf("Array Contents: [ ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]\n");
}

// Destructor-like function
void freeArray(SmartArray *arr) {
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    printf("--- ADT Test Cases: SmartArray ---\n");
    
    SmartArray myArray;
    
    // Test 1: Initialization
    printf("\nTest 1: Initializing SmartArray of capacity 3\n");
    initArray(&myArray, 3);
    display(&myArray);
    
    // Test 2: Insertion
    printf("\nTest 2: Inserting elements\n");
    insert(&myArray, 10);
    insert(&myArray, 20);
    insert(&myArray, 30);
    display(&myArray);
    
    // Test 3: Capacity bounds check (Should fail gracefully)
    printf("\nTest 3: Exceeding capacity\n");
    insert(&myArray, 40); 
    
    // Test 4: Cleanup
    printf("\nTest 4: Freeing ADT memory\n");
    freeArray(&myArray);
    printf("Memory freed.\n");

    return 0;
}
