#include <stdio.h>
#include <stdlib.h>

/*
 * Linear DS: Doubly Linked List (DLL)
 * Demonstrates node structure with prev/next pointers, insertion, traversal
 */

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted at front: %d\n", data);
}

// Forward Traversal
void displayForward(Node* head) {
    printf("DLL Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Backward Traversal
void displayBackward(Node* head) {
    if (head == NULL) return;
    // Go to last node
    while (head->next != NULL) {
        head = head->next;
    }
    printf("DLL Backward: NULL ");
    // Traverse backwards
    while (head != NULL) {
        printf("<-> %d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    printf("--- Doubly Linked List Test Cases ---\n\n");
    
    insertFront(&head, 30);
    insertFront(&head, 20);
    insertFront(&head, 10);
    
    printf("\nTest 1: Forward Traversal\n");
    displayForward(head);
    
    printf("\nTest 2: Backward Traversal\n");
    displayBackward(head);
    
    return 0;
}
