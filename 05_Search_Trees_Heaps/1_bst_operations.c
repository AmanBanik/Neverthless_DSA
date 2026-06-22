#include <stdio.h>
#include <stdlib.h>

/*
 * Search Trees: Binary Search Tree (BST) Operations
 * Supports Insertion, Searching, and Inorder Traversal.
 */

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST (Recursively)
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root; // Return unchanged node pointer
}

// Search in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Inorder traversal produces a sorted sequence
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    
    printf("--- BST Operations Test Cases ---\n\n");
    
    printf("Test 1: Insertion\n");
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder Traversal (Should be sorted):\n-> ");
    inorder(root);
    printf("\n");
    
    printf("\nTest 2: Search\n");
    int keyToFind = 60;
    Node* res = search(root, keyToFind);
    if (res != NULL) {
        printf("Found %d in the BST!\n", keyToFind);
    } else {
        printf("%d not found.\n", keyToFind);
    }
    
    keyToFind = 100;
    res = search(root, keyToFind);
    if (res != NULL) {
        printf("Found %d in the BST!\n", keyToFind);
    } else {
        printf("%d not found.\n", keyToFind);
    }
    
    return 0;
}
