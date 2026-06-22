#include <stdio.h>

/*
 * Advanced: Backtracking - N-Queens Problem
 * Place N queens on an NxN chessboard such that no two attack each other.
 */

#define N 4 // Using 4 for a concise terminal output

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j]) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if a queen can be safely placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i]) return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}

// A recursive utility function to solve N Queen problem
int solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed
    if (col >= N) return 1;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1)) return 1;

            // BACKTRACK: If placing queen here doesn't lead to a solution
            board[i][col] = 0; // Remove queen
        }
    }

    // If queen can not be place in any row in this column col, return false
    return 0;
}

int main() {
    printf("--- Backtracking: %d-Queens Problem ---\n\n", N);
    
    int board[N][N] = { {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} };

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution Found:\n");
        printSolution(board);
    }
    
    return 0;
}
