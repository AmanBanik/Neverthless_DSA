#include <stdio.h>

#define MAX_SIZE 5

/*
 * Linear DS: Stack (LIFO) Array Implementation
 * Supports Push, Pop, Peek operations
 */

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize Stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if Stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if Stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push operation
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("Pushed: %d\n", value);
}

// Pop operation
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Peek operation (view top element without removing)
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    initStack(&s);
    
    printf("--- Stack (Array) Test Cases ---\n\n");
    
    printf("Test 1: Push elements\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("\nTest 2: Peek top element\n");
    printf("Top element is: %d\n", peek(&s));
    
    printf("\nTest 3: Pop elements\n");
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    
    printf("\nTest 4: Stack Overflow test\n");
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70); // Should trigger overflow
    
    printf("\nTest 5: Empty stack completely\n");
    while(!isEmpty(&s)) {
        printf("Popped: %d\n", pop(&s));
    }
    
    // Trigger underflow
    pop(&s);
    
    return 0;
}
