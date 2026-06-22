#include <stdio.h>

/*
 * Advanced: Dynamic Programming - 0/1 Knapsack Problem
 * Given N items, each with a weight and a value, determine the maximum value
 * you can put in a knapsack of capacity W. You cannot break an item (0/1 property).
 *
 * Approach: Bottom-Up DP (Tabulation) using a 2D table.
 * Time: O(N * W), Space: O(N * W)
 */

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: 0 items or 0 capacity
            }
            else if (wt[i - 1] <= w) {
                // Choice: Include current item OR Exclude current item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else {
                // Item is too heavy, must exclude
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    printf("--- DP: 0/1 Knapsack Test Cases ---\n\n");
    
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);
    
    printf("Items: 3\n");
    printf("Values: [60, 100, 120]\n");
    printf("Weights: [10, 20, 30]\n");
    printf("Capacity: %d\n\n", W);
    
    printf("Maximum value we can obtain: %d (Expected: 220)\n", knapSack(W, wt, val, n));
    
    return 0;
}
