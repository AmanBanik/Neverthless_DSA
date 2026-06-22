# Walkthrough: Graphs & Recursion

## Graphs

A Graph $G = (V, E)$ consists of a set of Vertices (nodes) and Edges (connections).

### Terminologies
* **Directed Graph:** Edges have a direction (A $\rightarrow$ B).
* **Undirected Graph:** Edges are bidirectional (A $-$ B).
* **Weighted Graph:** Edges have a cost/weight associated with them.

### Representation
1. **Adjacency Matrix:** A 2D array of size $V \times V$. Good for dense graphs. $O(V^2)$ space.
2. **Adjacency List:** An array of linked lists. Good for sparse graphs. $O(V + E)$ space.

### Traversals
1. **Breadth First Search (BFS):** Explores neighbors first. Uses a **Queue**.
2. **Depth First Search (DFS):** Explores as deep as possible before backtracking. Uses a **Stack** (or Recursion).

---

## Recursion

A technique where a function calls itself to solve smaller instances of the same problem.
* Must always have a **Base Case** to prevent infinite loops.
* **Recursive Step:** The part where the function calls itself.

### Tail Recursion
If the recursive call is the absolute last operation in the function, it is Tail Recursive.
* Modern compilers can optimize tail recursion so it doesn't add a new frame to the Call Stack (saving $O(N)$ memory).

### When NOT to use Recursion
* When calculating Fibonacci numbers via basic recursion, the time complexity is $O(2^N)$ because the same subproblems are solved repeatedly. Iteration (or Dynamic Programming) is better here.

### Removal of Recursion
Any recursive function can be rewritten iteratively using a loop and an explicit Stack data structure.
