#include <stdio.h>

/*
 * Applied: Two Pointers - Two Sum (Sorted Array)
 * Given a 1-indexed array of integers that is already sorted in non-decreasing order,
 * find two numbers such that they add up to a specific target number.
 *
 * Approach: Two Pointers (Left and Right)
 * Time: O(N), Space: O(1)
 */

void twoSumSorted(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            printf("Found target %d at indices %d and %d (Values: %d + %d)\n", 
                    target, left, right, arr[left], arr[right]);
            return;
        } 
        else if (sum < target) {
            left++; // We need a larger sum, move left pointer right
        } 
        else {
            right--; // We need a smaller sum, move right pointer left
        }
    }
    printf("No two sum solution found for target %d\n", target);
}

int main() {
    printf("--- Two Sum (Sorted) Test Cases ---\n\n");
    
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array: [2, 7, 11, 15]\n");
    
    // Test 1: Exists
    twoSumSorted(arr, n, 9);  // Expected: 2 + 7
    
    // Test 2: Exists
    twoSumSorted(arr, n, 18); // Expected: 7 + 11
    
    // Test 3: Does not exist
    twoSumSorted(arr, n, 20);
    
    return 0;
}
