#include <stdio.h>

/*
 * Advanced: Backtracking - Sudoku Solver
 * Solves a 9x9 Sudoku puzzle using backtracking.
 */

#define N 9

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", grid[row][col]);
            if ((col+1)%3==0 && col<8) printf(" |");
        }
        printf("\n");
        if ((row+1)%3==0 && row<8) printf("-----------------------\n");
    }
}

// Checks whether it will be legal to assign num to the given row, col
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check if we find the same num in the similar row
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num) return 0;

    // Check if we find the same num in the similar column
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num) return 0;

    // Check if we find the same num in the particular 3*3 matrix
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num) return 0;

    return 1;
}

int solveSudoku(int grid[N][N], int row, int col) {
    // Base Case: If we have reached the 8th row and 9th column
    if (row == N - 1 && col == N) return 1;

    // Move to next row if column reaches 9
    if (col == N) {
        row++; col = 0;
    }

    // Skip pre-filled cells
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assign num
            grid[row][col] = num;

            // Recur
            if (solveSudoku(grid, row, col + 1)) return 1;
        }
        // BACKTRACK: Remove num
        grid[row][col] = 0;
    }
    return 0;
}

int main() {
    printf("--- Backtracking: Sudoku Solver ---\n\n");
    
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0) == 1) {
        printf("Sudoku Solved Successfully:\n\n");
        printGrid(grid);
    } else {
        printf("No solution exists");
    }

    return 0;
}
