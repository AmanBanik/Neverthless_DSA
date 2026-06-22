#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Applied: Trees - Validate Binary Search Tree
 * Check if a given binary tree is a valid BST.
 *
 * Approach: Recursive DFS with Boundaries
 * Pass down the allowed (min, max) limits to the children.
 * Time: O(N), Space: O(H)
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

// Helper function passing min and max limits
int validateBSTHelper(Node* root, long minVal, long maxVal) {
    if (root == NULL) return 1; // Base case: null node is valid
    
    if (root->data <= minVal || root->data >= maxVal) {
        return 0; // False
    }
    
    // Left child must be smaller than root->data
    // Right child must be larger than root->data
    return validateBSTHelper(root->left, minVal, root->data) &&
           validateBSTHelper(root->right, root->data, maxVal);
}

int isValidBST(Node* root) {
    return validateBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    printf("--- Validate BST Test Cases ---\n\n");
    
    // Valid BST
    //      2
    //     / \
    //    1   3
    Node* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);
    
    printf("Test 1 (Valid BST): %s\n", isValidBST(root1) ? "Valid" : "Invalid");
    
    // Invalid BST
    //      5
    //     / \
    //    1   4
    //       / \
    //      3   6
    Node* root2 = createNode(5);
    root2->left = createNode(1);
    root2->right = createNode(4);
    root2->right->left = createNode(3);
    root2->right->right = createNode(6);
    
    printf("Test 2 (Invalid BST): %s\n", isValidBST(root2) ? "Valid" : "Invalid");
    
    return 0;
}
