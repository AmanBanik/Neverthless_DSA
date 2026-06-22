#include <stdio.h>

/*
 * Searching: Sequential (Linear) and Ordered Sequential Search
 */

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i; // Found
    }
    return -1; // Not found
}

// For sorted arrays: We can stop early!
int orderedSequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
        if (arr[i] > target) return -1; // Stop early
    }
    return -1;
}

int main() {
    printf("--- Sequential Search Test Cases ---\n\n");
    
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int target = 40;
    printf("\nTest 1: Sequential Search for %d\n", target);
    int res = sequentialSearch(arr, n, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    target = 35;
    printf("\nTest 2: Ordered Sequential Search for %d (Stops early!)\n", target);
    res = orderedSequentialSearch(arr, n, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found (stopped searching when element exceeded 35)\n");
    
    return 0;
}
