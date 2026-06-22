#include <stdio.h>

/*
 * Searching: Binary Search
 * Array MUST be sorted. O(log N) time complexity.
 */

int binarySearchIterative(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow
        
        if (arr[mid] == target) return mid;
        
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearchRecursive(arr, left, mid - 1, target);
        
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    printf("--- Binary Search Test Cases ---\n\n");
    
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Sorted Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int target = 23;
    printf("\nTest 1: Iterative search for %d\n", target);
    int res = binarySearchIterative(arr, n, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    target = 91;
    printf("\nTest 2: Recursive search for %d\n", target);
    res = binarySearchRecursive(arr, 0, n - 1, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    return 0;
}
