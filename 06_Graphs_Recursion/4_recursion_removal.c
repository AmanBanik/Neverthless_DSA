#include <stdio.h>
#include <stdlib.h>

/*
 * Recursion: Removal of Recursion
 * Converting a recursive function to an iterative one using a Stack.
 * 
 * We will convert a simple Recursive Print function to an Iterative one.
 */

// --- 1. The Recursive version ---
void printRecursive(int n) {
    if (n <= 0) return;
    printf("%d ", n);
    printRecursive(n - 1);
}

// --- 2. The Iterative version using Stack ---
#define MAX 100
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int val) { s->arr[++s->top] = val; }
int pop(Stack *s) { return s->arr[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }

void printIterative(int n) {
    Stack s; s.top = -1;
    
    // Simulate recursive descent by pushing to stack
    push(&s, n);
    
    while (!isEmpty(&s)) {
        int curr = pop(&s);
        if (curr <= 0) continue;
        
        printf("%d ", curr);
        
        // Push the next state
        // In recursion, we call (n-1). To simulate, we push (n-1)
        push(&s, curr - 1);
    }
}

int main() {
    printf("--- Removal of Recursion Test Cases ---\n\n");
    
    printf("Original Recursive Execution (n=5):\n-> ");
    printRecursive(5);
    printf("\n\n");
    
    printf("Converted Iterative Execution (n=5) using Explicit Stack:\n-> ");
    printIterative(5);
    printf("\n");
    
    return 0;
}
