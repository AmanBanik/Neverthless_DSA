# Walkthrough: Linear Data Structures

Linear data structures organize elements in a sequential manner, where each element is connected to its previous and next element.

## 1. Sequential Representation (Arrays)
Elements are stored in contiguous memory locations.
* **Pros:** $O(1)$ constant time access using an index.
* **Cons:** Fixed size, insertion/deletion is slow $O(N)$ because elements need to be shifted.

## 2. Linked Representation (Linked Lists)
Elements (Nodes) are scattered in memory, connected via pointers.
* **Pros:** Dynamic size, fast insertion/deletion $O(1)$ if you have the pointer to the node.
* **Cons:** Access is slow $O(N)$ because you must traverse from the head. Extra memory needed for pointers.

## Types of Linked Lists:
* **Singly Linked List (SLL):** Nodes point only to the next node.
* **Doubly Linked List (DLL):** Nodes point to both previous and next nodes.
* **Circular Linked List (CLL):** The last node points back to the first node.

## Derived Linear Structures:
* **Stack:** LIFO (Last In, First Out). Think of a stack of plates.
* **Queue:** FIFO (First In, First Out). Think of a line at a ticket counter.
* **Dequeue:** Double Ended Queue. Insertion and deletion can happen at both ends.
