#include <stdio.h>

/*
 * Sorting: Insertion Sorts (Straight & Shell)
 */

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// --- 1. Straight Insertion Sort ---
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --- 2. Shell Sort ---
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        
        // Do a gapped insertion sort
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    printf("--- Insertion & Shell Sort Test Cases ---\n\n");
    
    int arr1[] = {12, 11, 13, 5, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Original Array (Insertion Sort): ");
    printArray(arr1, n1);
    insertionSort(arr1, n1);
    printf("Sorted Array: ");
    printArray(arr1, n1);
    
    printf("\n");
    
    int arr2[] = {45, 23, 53, 12, 5, 87, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Original Array (Shell Sort): ");
    printArray(arr2, n2);
    shellSort(arr2, n2);
    printf("Sorted Array: ");
    printArray(arr2, n2);
    
    return 0;
}
