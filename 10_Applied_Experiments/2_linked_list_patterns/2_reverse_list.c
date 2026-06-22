#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Linked List - Reverse a Linked List
 * Given the head of a singly linked list, reverse the list in-place.
 *
 * Approach: 3 Pointers (prev, current, next)
 * Time: O(N), Space: O(1)
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

// Function to reverse the list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next; // Store next node
        curr->next = prev; // REVERSE the link
        prev = curr;       // Move prev one step forward
        curr = next;       // Move curr one step forward
    }
    
    return prev; // Prev becomes the new head
}

void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Reverse Linked List Test Cases ---\n\n");
    
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original List:\n");
    display(head);
    
    head = reverseList(head);
    
    printf("\nReversed List:\n");
    display(head);
    
    return 0;
}
