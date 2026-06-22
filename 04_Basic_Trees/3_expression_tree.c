#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Trees: Expression Tree
 * Used to evaluate a mathematical expression represented as a tree.
 */

typedef struct Node {
    char data; // Can be operator or operand
    struct Node *left, *right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Evaluates the expression tree via Postorder Traversal
int evaluate(Node* root) {
    // If it's a leaf node, it must be an operand
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // Convert char to int
    }
    
    // Recursively evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    
    // Apply operator at current node
    if (root->data == '+') return leftVal + rightVal;
    if (root->data == '-') return leftVal - rightVal;
    if (root->data == '*') return leftVal * rightVal;
    if (root->data == '/') return leftVal / rightVal;
    
    return 0;
}

int main() {
    /*
     * Creating Expression Tree for: (5 + 3) * 4
     *        *
     *       / \
     *      +   4
     *     / \
     *    5   3
     */
     
    Node* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('4');
    
    root->left->left = createNode('5');
    root->left->right = createNode('3');
    
    printf("--- Expression Tree Test Cases ---\n\n");
    printf("Expression: (5 + 3) * 4\n");
    
    int result = evaluate(root);
    printf("Evaluation Result: %d\n", result); // Expected: 32
    
    return 0;
}
