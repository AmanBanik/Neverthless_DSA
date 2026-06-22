#include <stdio.h>
#include <stdlib.h>

/*
 * Linear DS: Circular Linked List (CLL)
 * The last node points back to the first node.
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of Circular Linked List
void insertEnd(Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*tail == NULL) {
        *tail = newNode;
        newNode->next = newNode; // Points to itself
        printf("Inserted first element: %d\n", data);
        return;
    }
    
    newNode->next = (*tail)->next; // New node points to head
    (*tail)->next = newNode;       // Old tail points to new node
    *tail = newNode;               // Update tail to new node
    printf("Inserted at end: %d\n", data);
}

// Display the Circular List
void displayCLL(Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = tail->next; // Start from head
    printf("CLL: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(back to head)\n");
}

int main() {
    Node* tail = NULL; // We keep track of tail instead of head for efficiency in CLL
    
    printf("--- Circular Linked List Test Cases ---\n\n");
    
    insertEnd(&tail, 10);
    insertEnd(&tail, 20);
    insertEnd(&tail, 30);
    
    printf("\nTest: Displaying Circular List\n");
    displayCLL(tail);
    
    return 0;
}
