# Walkthrough: Backtracking

Backtracking is a refined brute force technique. It involves building a solution incrementally and removing (backtracking) solutions that fail to satisfy the constraints of the problem at any point in time.

## Concept
Think of it like navigating a maze:
1. You take a path.
2. If you hit a dead end, you don't just stand there; you **backtrack** to the previous intersection and try a different path.
3. You repeat this until you find the exit or exhaust all paths.

## Key Differences from Pure Recursion
Pure recursion often evaluates all branches unconditionally. Backtracking evaluates a branch, checks if it's still valid (`isValid()`), and if not, it **prunes** that branch (stops exploring it), saving immense computational time.

## Classic Problems
* **N-Queens:** Placing N chess queens on an N×N chessboard so that no two queens attack each other.
* **Sudoku Solver:** Filling a 9x9 grid where rows, columns, and 3x3 subgrids contain 1-9 uniquely.
* **Permutations / Combinations:** Generating all valid arrangements of a set.
