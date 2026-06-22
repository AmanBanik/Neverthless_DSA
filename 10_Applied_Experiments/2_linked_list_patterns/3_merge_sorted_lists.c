#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Linked List - Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a sorted list.
 * The list should be made by splicing together the nodes of the first two lists.
 *
 * Approach: Dummy Head Node & Two Pointers
 * Time: O(N + M), Space: O(1)
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

Node* mergeTwoLists(Node* l1, Node* l2) {
    // Create a dummy node to act as the starting anchor
    Node dummy; 
    dummy.data = -1;
    dummy.next = NULL;
    
    Node* tail = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach the remaining elements if any list is not empty
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;
    
    return dummy.next;
}

void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Merge Sorted Lists Test Cases ---\n\n");
    
    // List 1: 1 -> 2 -> 4
    Node* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    
    // List 2: 1 -> 3 -> 4
    Node* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);
    
    printf("List 1:\n");
    display(l1);
    
    printf("List 2:\n");
    display(l2);
    
    Node* mergedList = mergeTwoLists(l1, l2);
    
    printf("\nMerged List:\n");
    display(mergedList);
    
    return 0;
}
