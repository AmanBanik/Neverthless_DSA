#include <stdio.h>

#define MAX_SIZE 5

/*
 * Linear DS: Queue (FIFO) Array Implementation
 * Supports Enqueue, Dequeue operations
 */

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize Queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if Full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Check if Empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue operation (insert at rear)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) q->front = 0; // Initialize front on first insert
    q->arr[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation (remove from front)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front++];
    
    // Reset queue if all elements are deleted
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

// Display queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue: [ ]\n");
        return;
    }
    printf("Queue: [ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("]\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    printf("--- Queue (Array) Test Cases ---\n\n");
    
    printf("Test 1: Enqueue elements\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    
    printf("\nTest 2: Dequeue elements\n");
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
    
    printf("\nTest 3: Queue Full test\n");
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // Might fail depending on rear pointer (Linear Queue disadvantage)
    display(&q);
    
    return 0;
}
