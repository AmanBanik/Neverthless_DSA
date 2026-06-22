# Walkthrough: Applied Experiments & Interview Patterns

While previous modules taught you **how to build** data structures, this module teaches you **how to use them** to solve actual logical problems, much like those found on LeetCode or in technical interviews.

## The Strategy

When you see a problem, look for these hints to determine the pattern:

1. **Arrays / Strings:**
   * Is it sorted? $\rightarrow$ Think **Binary Search** or **Two Pointers**.
   * Asking for a contiguous subarray or maximum sum? $\rightarrow$ Think **Kadane's Algorithm** or **Sliding Window**.
   * Asking for frequencies of characters? $\rightarrow$ Use a fixed array as a **Hash Map** `count[256]`.

2. **Linked Lists:**
   * Asking to find the middle or detect a cycle? $\rightarrow$ Think **Fast & Slow Pointers** (Floyd's Tortoise and Hare).
   * Asking to reverse? $\rightarrow$ Master the 3-pointer trick (`prev`, `curr`, `next`).

3. **Stacks:**
   * Seeing matching pairs (`{}`, `()`) or parsing strings? $\rightarrow$ Use a **Stack**.
   * Asking for the "Next Greater Element"? $\rightarrow$ Think **Monotonic Stack**.

4. **Trees & Graphs:**
   * Exploring a 2D matrix/grid (like finding islands)? $\rightarrow$ Treat it as a graph and use **DFS** (Recursion).
   * Finding shortest paths? $\rightarrow$ Think **BFS** (Queue).
   * Need to validate a property top-to-bottom? $\rightarrow$ Pass min/max limits down through **DFS**.

Inside the subfolders, you will find self-contained C scripts for the foundational archetype questions of each pattern.
