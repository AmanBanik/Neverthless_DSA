#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Trees - Maximum Depth of Binary Tree
 * Find the max depth (height) of a binary tree.
 *
 * Approach: Recursive DFS
 * Depth = 1 + max(left_depth, right_depth)
 * Time: O(N), Space: O(H) where H is height of tree (call stack)
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(Node* root) {
    if (root == NULL) {
        return 0; // Base case: leaf node has depth 0
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    printf("--- Max Depth of Binary Tree Test Cases ---\n\n");
    
    /*
     * Tree:
     *      3
     *     / \
     *    9  20
     *       / \
     *      15  7
     */
    Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    
    printf("Calculated Max Depth: %d (Expected: 3)\n", maxDepth(root));
    
    return 0;
}
