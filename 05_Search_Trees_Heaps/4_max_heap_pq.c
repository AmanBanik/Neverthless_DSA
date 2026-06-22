#include <stdio.h>

#define MAX_HEAP_SIZE 10

/*
 * Search Trees: Max Heap & Priority Queue
 * Implemented using an Array because Heaps are Complete Binary Trees.
 * Parent(i) = (i - 1) / 2
 * LeftChild(i) = 2i + 1
 * RightChild(i) = 2i + 2
 */

typedef struct {
    int arr[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into Max Heap
void insert(MaxHeap *h, int value) {
    if (h->size >= MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    
    // Insert at the end
    int i = h->size;
    h->arr[i] = value;
    h->size++;
    
    // Up-heapify (Bubble up)
    while (i != 0 && h->arr[(i - 1) / 2] < h->arr[i]) {
        swap(&h->arr[(i - 1) / 2], &h->arr[i]);
        i = (i - 1) / 2;
    }
    printf("Inserted: %d\n", value);
}

// Heapify down (for deletion)
void maxHeapify(MaxHeap *h, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < h->size && h->arr[left] > h->arr[largest]) largest = left;
    if (right < h->size && h->arr[right] > h->arr[largest]) largest = right;
    
    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        maxHeapify(h, largest);
    }
}

// Extract max element (Priority Queue Dequeue)
int extractMax(MaxHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }
    
    int root = h->arr[0];
    
    // Move last element to root and shrink size
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    
    // Down-heapify
    maxHeapify(h, 0);
    
    return root;
}

void printHeap(MaxHeap *h) {
    printf("Heap Array: [ ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("]\n");
}

int main() {
    MaxHeap h;
    h.size = 0;
    
    printf("--- Max Heap (Priority Queue) Test Cases ---\n\n");
    
    printf("Test 1: Insertions\n");
    insert(&h, 10);
    insert(&h, 20);
    insert(&h, 15);
    insert(&h, 40);
    insert(&h, 50);
    insert(&h, 100);
    
    printHeap(&h);
    
    printf("\nTest 2: Extract Max (Dequeue by Priority)\n");
    printf("Extracted Max: %d\n", extractMax(&h));
    printHeap(&h);
    
    printf("Extracted Max: %d\n", extractMax(&h));
    printHeap(&h);
    
    return 0;
}
