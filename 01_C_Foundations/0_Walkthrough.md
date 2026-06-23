# Walkthrough: C Foundations & Memory

Before building complex data structures, we must understand how C manages memory.

## 1. Memory Layout in C
A typical C program's memory is divided into several segments:

```text
+----------------------+  <-- High Address
|     Stack (LIFO)     |  (Local variables, Function calls)
|          |           |
|          v           |
|                      |
|          ^           |
|          |           |
|     Heap (DMA)       |  (malloc, calloc, realloc)
+----------------------+
| Uninitialized Data   |  (BSS Segment)
+----------------------+
|  Initialized Data    |  (Global/Static vars)
+----------------------+
|    Code Segment      |  (Text / Instructions)
+----------------------+  <-- Low Address
```

* **Code Segment (Text):** Contains the compiled machine code. Read-only.
* **Data Segment:** Explicitly initialized global and static variables.
* **BSS Segment:** Uninitialized global and static variables (initialized to 0).
* **Stack:** Local variables, parameters, return addresses. Grows downwards. Extremely fast but limited in size.
* **Heap:** Dynamic memory allocation at runtime. Grows upwards. Managed manually using `malloc()`, `calloc()`, and `free()`.

## 2. Dynamic Memory Allocation (DMA)
When we don't know the size of data at compile time, we use the Heap.

### Core DMA Functions (`<stdlib.h>`)
* `malloc(size_t size)`: Allocates `size` bytes of uninitialized memory.
* `calloc(size_t num, size_t size)`: Allocates memory for an array and zero-initializes it.
* `realloc(void *ptr, size_t new_size)`: Resizes previously allocated memory.
* `free(void *ptr)`: Deallocates memory. Failing to use `free()` results in a **Memory Leak**.

### Key Concept: Pointers
Pointers store memory addresses. When allocating on the heap, `malloc()` returns a pointer to the starting address of that block.
