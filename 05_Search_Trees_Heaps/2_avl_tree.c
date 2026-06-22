#include <stdio.h>
#include <stdlib.h>

/*
 * Search Trees: AVL Tree (Height Balanced Tree)
 * Demonstrates Right Rotation (LL Case) and Left Rotation (RR Case) 
 * to maintain the O(log N) height property.
 */

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

int getHeight(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return node;
}

// Right rotate
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotate
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == NULL) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Insert and balance
Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else return node; // Equal keys are not allowed in BST

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // If node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    
    printf("--- AVL Tree Test Cases ---\n\n");
    printf("Inserting: 10, 20, 30, 40, 50, 25\n");

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Triggers RR rotation
    root = insert(root, 40);
    root = insert(root, 50); // Triggers RR rotation
    root = insert(root, 25); // Triggers RL rotation

    printf("\nPreorder traversal of the constructed AVL tree is:\n-> ");
    preorder(root);
    printf("\n(Expected: 30 20 10 25 40 50)\n");

    return 0;
}
