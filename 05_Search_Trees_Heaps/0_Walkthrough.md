# Walkthrough: Search Trees & Heaps

Standard binary trees are great, but searching them takes $O(N)$. We introduce rules to trees to optimize searching and retrieval.

## 1. Binary Search Tree (BST)
**Rule:** For every node, all elements in the **Left Subtree** are smaller, and all elements in the **Right Subtree** are larger.
* **Search / Insert / Delete:** $O(\log N)$ on average.
* **Worst Case:** $O(N)$ if the tree becomes skewed (looks like a Linked List).
* An **Inorder Traversal** of a BST yields elements in sorted order.

## 2. Height Balanced Trees (AVL Tree)
To fix the $O(N)$ worst-case of BSTs, we use self-balancing trees.
* **AVL Tree:** Introduces a "Balance Factor" for every node (`Height(Left) - Height(Right)`).
* If the balance factor goes out of the `[-1, 0, 1]` range, we perform **Rotations** (LL, RR, LR, RL) to balance the tree.

## 3. M-Way Search Trees & B-Trees
Binary trees limit a node to 2 children. **M-Way trees** allow a node to have $M$ children and $M-1$ keys.
* **B-Trees:** A highly balanced M-Way search tree optimized for systems that read/write large blocks of data (like Databases and File Systems).

## 4. Heaps & Priority Queues
A **Heap** is a Complete Binary Tree used to implement a Priority Queue.
* **Max Heap:** Root is the largest element. Every parent is greater than its children.
* **Min Heap:** Root is the smallest element.
* **Priority Queue:** Elements are dequeued based on priority (value) rather than FIFO order. $O(\log N)$ insertion and extraction.
