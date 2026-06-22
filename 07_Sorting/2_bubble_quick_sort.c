#include <stdio.h>

/*
 * Sorting: Exchange Sorts (Bubble & Quick)
 */

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// --- 1. Bubble Sort ---
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break; // Optimized to stop if already sorted
    }
}

// --- 2. Quick Sort ---
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing last element as pivot
    int i = (low - 1);     // Index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    printf("--- Bubble & Quick Sort Test Cases ---\n\n");
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Original Array (Bubble Sort): ");
    printArray(arr1, n1);
    bubbleSort(arr1, n1);
    printf("Sorted Array: ");
    printArray(arr1, n1);
    
    printf("\n");
    
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Original Array (Quick Sort): ");
    printArray(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    printf("Sorted Array: ");
    printArray(arr2, n2);
    
    return 0;
}
