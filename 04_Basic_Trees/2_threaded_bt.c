#include <stdio.h>
#include <stdlib.h>

/*
 * Trees: Single Threaded Binary Tree (Inorder Threading)
 * Replaces NULL right pointers with a thread pointing to the inorder successor.
 */

typedef struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded; // 1 if right pointer is a thread, 0 if it's a normal child link
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Leftmost node in a tree
Node* leftmost(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Inorder Traversal without recursion or stack using threads
void inorderThreaded(Node* root) {
    if (root == NULL) return;
    
    // Start at the leftmost node
    Node* current = leftmost(root);
    
    while (current != NULL) {
        printf("%d ", current->data);
        
        // If the right pointer is a thread, follow it
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Otherwise, go to the leftmost node in the right subtree
            current = leftmost(current->right);
        }
    }
}

int main() {
    /*
     * Creating a Threaded Binary Tree manually for demonstration:
     *        1
     *       / \
     *      2   3
     *       \
     *        4
     * Inorder should be: 2, 4, 1, 3
     */
     
    Node* root = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    
    root->left = node2;
    root->right = node3;
    node2->right = node4; // Normal link
    
    // Setting up the threads:
    // 4's inorder successor is 1
    node4->right = root;
    node4->isThreaded = 1;
    
    // 3 has no successor, remains NULL
    
    printf("--- Threaded Binary Tree Test Cases ---\n\n");
    printf("Inorder Traversal (Without Recursion or Stack!):\n-> ");
    inorderThreaded(root);
    printf("\n");
    
    return 0;
}
