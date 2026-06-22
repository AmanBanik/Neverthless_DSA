#include <stdio.h>

#define MAX_SIZE 5

/*
 * Linear DS: Dequeue (Double Ended Queue) Array Implementation
 * Elements can be inserted and deleted from both front and rear.
 */

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Dequeue;

void initDequeue(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Dequeue *dq) {
    // True if circular queue is full
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || dq->front == dq->rear + 1);
}

int isEmpty(Dequeue *dq) {
    return (dq->front == -1);
}

void insertFront(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is Full! Cannot insert at front.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front = dq->front - 1;
    }
    dq->arr[dq->front] = value;
    printf("Inserted at Front: %d\n", value);
}

void insertRear(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is Full! Cannot insert at rear.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear = dq->rear + 1;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted at Rear: %d\n", value);
}

int deleteFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is Empty! Cannot delete from front.\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) { // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front = dq->front + 1;
    }
    return value;
}

int deleteRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is Empty! Cannot delete from rear.\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) { // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear = dq->rear - 1;
    }
    return value;
}

int main() {
    Dequeue dq;
    initDequeue(&dq);
    
    printf("--- Dequeue Test Cases ---\n\n");
    
    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    
    printf("Deleted from Front: %d\n", deleteFront(&dq));
    printf("Deleted from Rear: %d\n", deleteRear(&dq));
    
    return 0;
}
