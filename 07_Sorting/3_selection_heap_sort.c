#include <stdio.h>

/*
 * Sorting: Selection Sorts (Straight Selection & Heap Sort)
 */

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// --- 1. Straight Selection Sort ---
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// --- 2. Heap Sort ---
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

int main() {
    printf("--- Selection & Heap Sort Test Cases ---\n\n");
    
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Original Array (Selection Sort): ");
    printArray(arr1, n1);
    selectionSort(arr1, n1);
    printf("Sorted Array: ");
    printArray(arr1, n1);
    
    printf("\n");
    
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Original Array (Heap Sort): ");
    printArray(arr2, n2);
    heapSort(arr2, n2);
    printf("Sorted Array: ");
    printArray(arr2, n2);
    
    return 0;
}
