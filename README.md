<div align="center">
  <h1>🧠 DSA in C: From Zero to Hero 🚀</h1>
  <p><i>Because sometimes you just need to manage memory yourself.</i></p>
  <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExcGNyZjM2NDVnbzNxaWNwZmhkZGxtbzcyN2hxNjVsdm1hMjF2cmI4cCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/VbnUQpnihPSIgIXuZv/giphy.gif" width="300" alt="Hacker Cat">
</div>

---

## 🎯 The Intuition

Why learn Data Structures and Algorithms (DSA) in **C**? 

In modern languages like Python or Java, things like dynamic arrays, garbage collection, and hash maps are handed to you on a silver platter. In C, **you are the architect**. 

Learning DSA in C forces you to understand exactly how memory is allocated, how pointers connect disparate blocks of data in the heap, and why a Memory Leak is your worst enemy. Once you master the mechanics of building a Linked List or a B-Tree using raw pointers, every other programming language feels like playing on "Easy Mode".

## 🔥 The Cause

This repository was meticulously crafted to serve as the **ultimate bridge** for students dealing with C programming. 

It starts from the absolute college basics (Syllabus mapping) and scales up to advanced algorithmic problem-solving techniques used in LeetCode and FAANG interviews. This is for the collective good of anyone who has ever stared at a `Segmentation fault (core dumped)` error and questioned their life choices.

<div align="center">
  <img src="https://http.cat/500" width="300" alt="Internal Server Error Cat">
  <p><i>We've all been there.</i></p>
</div>

---

## 🏗️ Repository Architecture

The codebase is divided into **12 Modules** ranging from `00` to `11`. 

### 📚 Part 1: Core Mechanics (College Syllabus)
* **`01_C_Foundations`**: Stack, Heap, and Dynamic Memory Allocation (`malloc`, `free`).
* **`02_Concepts_ADTs`**: Abstract Data Types.
* **`03_Linear_DS`**: Arrays, Stacks, Queues, and Linked Lists.
* **`04_Basic_Trees` & `05_Search_Trees_Heaps`**: Binary Trees, BSTs, AVL Trees, Heaps, and B-Trees.
* **`06_Graphs_Recursion`**: DFS, BFS, and the beauty of Tail Recursion.
* **`07_Sorting` & `08_Searching`**: Quick Sort, Merge Sort, Binary Search, Interpolation Search.
* **`09_Hashing`**: Collisions, Open Addressing, Chaining.

### 🚀 Part 2: Applied Mastery (LeetCode & Advanced)
* **`10_Applied_Experiments`**: The "Archetype" questions. Learn the 7 core patterns (Two Pointers, Sliding Window, Monotonic Stack, Fast/Slow Pointers, Grid DFS) that unlock hundreds of LeetCode problems.
* **`11_Advanced_Algorithms_Bridge`**: Taking it beyond college. Dynamic Programming (Memoization vs Tabulation), Greedy Algorithms (Dijkstra's), String Algorithms (KMP), Advanced DS (Tries, Union-Find), and Backtracking (Sudoku Solver, N-Queens).

---

## 🛠️ How to Use This Repo

1. **Read the Walkthroughs**: Inside **every single module**, you will find a `0_Walkthrough.md` file. Read this first! It explains the *Intuition* and *Time Complexity* without the clutter of code.
2. **Compile the Scripts**: Every `.c` file is completely self-contained with **no header slop**. They all have a `main()` function filled with clear, backtrackable `printf` test cases.
3. **Run them**:
   ```bash
   # Navigate to a module
   cd 03_Linear_DS
   
   # Compile using GCC
   gcc 5_singly_linked_list.c -o sll
   
   # Run the executable
   ./sll
   ```
4. **Follow the Prints**: The output is designed to be highly readable, showing exactly what elements are inserted, popped, or searched.

---

<div align="center">
  <h3>Happy Coding!</h3>
  <img src="https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif" width="300" alt="Typing Cat">
  <p><i>May your pointers never be NULL.</i></p>
</div>
