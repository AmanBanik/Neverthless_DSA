#include <stdio.h>

/*
 * Applied: Binary Search - Find Minimum in Rotated Sorted Array
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
 * Given the sorted rotated array, return the minimum element of this array in O(log n) time.
 *
 * Approach: Modified Binary Search
 * We compare the mid element with the rightmost element to determine which half is unsorted.
 * The minimum element MUST lie in the unsorted half!
 * Time: O(log N), Space: O(1)
 */

int findMin(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If mid element is greater than the rightmost element,
        // it means the minimum is to the right of mid.
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } 
        // Otherwise, the right half is sorted, so the minimum is 
        // at mid or to the left of mid.
        else {
            right = mid;
        }
    }
    
    // When left == right, we found the minimum
    return arr[left];
}

int main() {
    printf("--- Find Minimum in Rotated Sorted Array Test Cases ---\n\n");
    
    int arr1[] = {3, 4, 5, 1, 2};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Array: [3, 4, 5, 1, 2]\n");
    printf("Minimum: %d (Expected: 1)\n\n", findMin(arr1, n1));
    
    int arr2[] = {4, 5, 6, 7, 0, 1, 2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Array: [4, 5, 6, 7, 0, 1, 2]\n");
    printf("Minimum: %d (Expected: 0)\n\n", findMin(arr2, n2));
    
    int arr3[] = {11, 13, 15, 17};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("Array: [11, 13, 15, 17] (Not rotated)\n");
    printf("Minimum: %d (Expected: 11)\n", findMin(arr3, n3));
    
    return 0;
}
