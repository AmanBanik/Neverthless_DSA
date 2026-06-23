# Walkthrough: Hashing

Searching normally takes $O(\log N)$ at best (Binary Search). **Hashing** allows us to search, insert, and delete in $O(1)$ average time.

## 1. Concepts
* **Hash Function:** A mathematical function that converts a large Key (like a name or ID) into a small integer (index).
* **Hash Table / Scatter Table:** The array where the actual data is stored based on the index computed by the hash function.
* **Collision:** When two different keys hash to the same index.

## 2. Hash Function Implementations
* **Division Method:** `index = key % TableSize` (Most common).
* **Multiplication Method:** `index = floor(TableSize * (key * A % 1))`.
* **Mid-Square Method:** Square the key, take the middle digits.

## 3. Handling Collisions
Since collisions are inevitable, we must handle them.

### Open Addressing (Closed Hashing)
If a collision occurs, find another open slot in the table.
* **Linear Probing:** Check the next slot `(index + 1) % size`, then `(index + 2) % size`, etc.
* **Quadratic Probing:** Check `(index + 1^2)`, `(index + 2^2)`, etc.
* **Double Hashing:** Use a second hash function to determine the step size.

### Chaining (Open Hashing)
Each slot in the array is a pointer to a **Linked List**. If a collision occurs, simply append the new element to the linked list at that index. No probing is needed, but it requires extra memory for pointers.

```text
Hash Table Array
[ 0 ] -> NULL
[ 1 ] -> [ Key: 15 ] -> [ Key: 22 ] -> NULL   <-- Collision resolved via chaining
[ 2 ] -> [ Key: 9 ] -> NULL
[ 3 ] -> NULL
```
