#include <stdio.h>
#include <stdlib.h>

/*
 * Linear DS: Singly Linked List (SLL)
 * Demonstrates node structure, insertion (front/end), deletion, traversal
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted at front: %d\n", data);
}

// Insert at end
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted at end (first element): %d\n", data);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted at end: %d\n", data);
}

// Delete from beginning
void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted from front: %d\n", temp->data);
    free(temp);
}

// Traverse and display list
void displayList(Node* head) {
    printf("SLL: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    printf("--- Singly Linked List Test Cases ---\n\n");
    
    printf("Test 1: Insertions\n");
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertFront(&head, 5);
    displayList(head);
    
    printf("\nTest 2: Deletion\n");
    deleteFront(&head);
    displayList(head);
    
    // Clean up
    while(head != NULL) {
        deleteFront(&head);
    }
    
    return 0;
}
