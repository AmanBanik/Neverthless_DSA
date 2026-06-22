#include <stdio.h>

/*
 * Sorting: Radix Sort (Distribution Sort)
 * Sorts digit by digit using Counting Sort as a subroutine.
 */

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSortForRadix(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0};
    
    // Store count of occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
        
    // Change count[i] so that it contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
        
    // Build the output array (Backwards for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    
    // Do counting sort for every digit.
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortForRadix(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("--- Radix Sort Test Cases ---\n\n");
    
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original Array: ");
    printArray(arr, n);
    
    radixSort(arr, n);
    
    printf("Sorted Array:   ");
    printArray(arr, n);
    
    return 0;
}
