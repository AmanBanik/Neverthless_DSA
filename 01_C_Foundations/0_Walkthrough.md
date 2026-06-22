# Walkthrough: C Foundations & Memory

Before building complex data structures, we must understand how C manages memory.

## 1. Memory Layout in C
A typical C program's memory is divided into several segments:
* **Code Segment (Text):** Contains the compiled machine code of the program. Read-only.
* **Data Segment:** Contains explicitly initialized global and static variables.
* **BSS Segment:** Contains uninitialized global and static variables (initialized to 0 by default).
* **Stack:** Used for local variables, function parameters, and return addresses. It grows downwards. Extremely fast but limited in size.
* **Heap:** Used for dynamic memory allocation at runtime. It grows upwards. Managed manually by the programmer using `malloc()`, `calloc()`, and `free()`.

## 2. Dynamic Memory Allocation (DMA)
When we don't know the size of data at compile time (e.g., reading an unknown number of user records), we use the Heap.

### Core DMA Functions (`<stdlib.h>`)
* `malloc(size_t size)`: Allocates `size` bytes of uninitialized memory.
* `calloc(size_t num, size_t size)`: Allocates memory for an array of `num` elements, each of `size` bytes, and initializes all bytes to zero.
* `realloc(void *ptr, size_t new_size)`: Resizes previously allocated memory.
* `free(void *ptr)`: Deallocates the memory previously allocated, returning it to the system. Failing to use `free()` results in a **Memory Leak**.

### Key Concept: Pointers
Pointers are variables that store memory addresses. When you allocate memory on the heap, functions like `malloc()` return a pointer to the starting address of that memory block.
