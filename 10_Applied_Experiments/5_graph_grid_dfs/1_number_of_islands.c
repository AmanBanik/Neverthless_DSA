#include <stdio.h>

/*
 * Applied: Graphs - Number of Islands
 * Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), 
 * return the number of islands. (An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically).
 *
 * Approach: DFS on a Grid
 * Iterate through the grid. When you find a '1', increment island count and 
 * trigger DFS to "sink" the entire island (turn connected 1s to 0s) to avoid recounting.
 * Time: O(M * N), Space: O(M * N) for recursion stack.
 */

#define ROWS 4
#define COLS 5

void dfsSink(char grid[ROWS][COLS], int r, int c) {
    // Check bounds and if it's water
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == '0') {
        return;
    }
    
    // Sink the land
    grid[r][c] = '0';
    
    // Explore all 4 adjacent directions
    dfsSink(grid, r + 1, c); // Down
    dfsSink(grid, r - 1, c); // Up
    dfsSink(grid, r, c + 1); // Right
    dfsSink(grid, r, c - 1); // Left
}

int numIslands(char grid[ROWS][COLS]) {
    int count = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1') {
                count++; // Found a new island!
                dfsSink(grid, i, j); // Sink it so we don't count it again
            }
        }
    }
    return count;
}

int main() {
    printf("--- Number of Islands (Grid DFS) Test Cases ---\n\n");
    
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    printf("Grid:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\nNumber of Islands: %d (Expected: 3)\n", numIslands(grid));
    
    return 0;
}
