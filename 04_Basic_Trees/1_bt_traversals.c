#include <stdio.h>
#include <stdlib.h>

/*
 * Trees: Binary Tree Traversals
 * Demonstrates basic BT creation and recursive Preorder, Inorder, and Postorder traversals.
 */

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    /*
     * Creating the following Binary Tree:
     *        1
     *       / \
     *      2   3
     *     / \
     *    4   5
     */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("--- Binary Tree Traversals Test Cases ---\n\n");
    
    printf("Preorder Traversal (Root, Left, Right):\n-> ");
    preorder(root); // Expected: 1 2 4 5 3
    printf("\n\n");

    printf("Inorder Traversal (Left, Root, Right):\n-> ");
    inorder(root); // Expected: 4 2 5 1 3
    printf("\n\n");

    printf("Postorder Traversal (Left, Right, Root):\n-> ");
    postorder(root); // Expected: 4 5 2 3 1
    printf("\n\n");

    return 0;
}
