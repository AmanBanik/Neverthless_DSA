#include <stdio.h>

/*
 * Searching: Interpolation Search
 * Array MUST be sorted AND uniformly distributed for best performance O(log(log N)).
 */

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = (n - 1);
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        // The Interpolation formula! Probes the expected position.
        // Similar to Binary Search's: mid = low + (high - low)/2
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        
        if (arr[pos] == target) return pos;
        
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    printf("--- Interpolation Search Test Cases ---\n\n");
    
    // Uniformly distributed array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Sorted Uniform Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int target = 80;
    printf("\nTest 1: Search for %d\n", target);
    int res = interpolationSearch(arr, n, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    target = 105;
    printf("\nTest 2: Search for %d\n", target);
    res = interpolationSearch(arr, n, target);
    if (res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    return 0;
}
