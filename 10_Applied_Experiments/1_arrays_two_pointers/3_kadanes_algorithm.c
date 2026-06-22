#include <stdio.h>

/*
 * Applied: Kadane's Algorithm - Maximum Subarray Sum
 * Given an integer array, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 *
 * Approach: Dynamic Programming / Greedy (Kadane's Alg)
 * Keep track of current subarray sum. If it goes below 0, reset it, 
 * because a negative sum will only pull down the sum of future elements.
 * Time: O(N), Space: O(1)
 */

int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < n; i++) {
        // Should we add the current element to the existing subarray, 
        // or start a completely new subarray from the current element?
        current_max = (arr[i] > current_max + arr[i]) ? arr[i] : (current_max + arr[i]);
        
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }
    return max_so_far;
}

int main() {
    printf("--- Maximum Subarray (Kadane's) Test Cases ---\n\n");
    
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]\n");
    printf("Max Subarray Sum: %d (Expected: 6, from [4, -1, 2, 1])\n\n", maxSubArray(arr1, n1));
    
    int arr2[] = {5, 4, -1, 7, 8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Array: [5, 4, -1, 7, 8]\n");
    printf("Max Subarray Sum: %d (Expected: 23)\n\n", maxSubArray(arr2, n2));
    
    return 0;
}
