# DSA in C - Syllabus Brief & Intuition

Welcome to the comprehensive guide to Data Structures and Algorithms in C. This repository is structured to take you from the foundational concepts of C (how memory works) all the way to complex non-linear data structures like Graphs and B-Trees, and finally into advanced interview-style algorithmic problem solving.

## Intuition

Before diving into abstract data types or complex trees, it's crucial to understand **why** we need them.
* **Information & Meaning:** Data is just raw facts. Data Structures give data meaning and organization.
* **Memory Management:** In C, unlike Python or Java, you are the master of memory. You must know where your variables live (Stack vs. Heap) to avoid memory leaks.
* **Performance:** Choosing the right data structure (e.g., Hash Table vs. Linked List) reduces the time complexity of searching from $O(N)$ to $O(1)$. 

## Course Breakdown

### Core Modules (College Syllabus Mapping)
* **01_C_Foundations:** Understanding the Stack, Heap, and Dynamic Memory Allocation (DMA).
* **02_Concepts_ADTs:** Abstract Data Types, separating the "what" from the "how".
* **03_Linear_DS:** Arrays, Stacks, Queues, and Linked Lists. Data is arranged in a sequential manner.
* **04_Basic_Trees & 05_Search_Trees_Heaps:** Non-linear hierarchical structures (Binary Trees, BSTs, AVL, Heaps, B-Trees).
* **06_Graphs_Recursion:** Complex network representations and algorithmic design patterns.
* **07_Sorting:** Ordering data efficiently (Merge, Quick, Heap, Radix sorts).
* **08_Searching:** Finding data efficiently (Binary Search, Interpolation).
* **09_Hashing:** Direct access to data using hash functions to handle collisions.

### Applied & Advanced Modules (Beyond Syllabus)
* **10_Applied_Experiments:** Essential interview-style questions and "base archetype" patterns (e.g., Two Pointers, Sliding Window, grid DFS, Monotonic Stacks). Bridging theory and practical problem solving.
* **11_Advanced_Algorithms_Bridge:** Taking DSA further with Dynamic Programming, Greedy Algorithms, KMP String Matching, Advanced DS (Union-Find, Tries), Backtracking (N-Queens, Sudoku), and Cryptography Basics.

This repository is built for collective learning—each C script is self-contained with minimal boilerplate, focusing purely on the logic and understandable, backtrackable test cases.
