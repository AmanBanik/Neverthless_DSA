#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Linked List - Detect Cycle
 * Determine if a linked list has a cycle in it.
 *
 * Approach: Floyd's Tortoise and Hare (Fast & Slow Pointers)
 * Slow pointer moves 1 step. Fast pointer moves 2 steps.
 * If there's a loop, they will eventually meet. If fast reaches NULL, no loop.
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

int hasCycle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return 0; // No cycle
    }
    
    Node *slow = head;
    Node *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // 1 hop
        fast = fast->next->next;    // 2 hops
        
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }
    return 0; // Reached the end, no cycle
}

int main() {
    printf("--- Detect Cycle Test Cases ---\n\n");
    
    // Creating List 1: 1 -> 2 -> 3 -> 4 -> NULL (No Cycle)
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    
    printf("Test 1: Linear List\n");
    if (hasCycle(head1)) printf("Result: Cycle Detected!\n");
    else printf("Result: No Cycle.\n");
    
    // Creating List 2: 1 -> 2 -> 3 -> 4 -| 
    //                        ^_________| (Cycle back to 2)
    Node* head2 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    
    head2->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates the cycle
    
    printf("\nTest 2: Circular/Looped List\n");
    if (hasCycle(head2)) printf("Result: Cycle Detected!\n");
    else printf("Result: No Cycle.\n");
    
    return 0;
}
