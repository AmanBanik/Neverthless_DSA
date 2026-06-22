#include <stdio.h>
#include <stdlib.h>

#define M 3 // M-Way Tree (B-Tree of order 3)

/*
 * Search Trees: B-Tree Node Concept
 * This file illustrates the structural design of an M-Way tree node.
 * A B-Tree node of order M can have:
 *  - At most M children
 *  - At most M-1 keys
 */

typedef struct BTreeNode {
    int keys[M - 1];              // Array of keys
    struct BTreeNode *children[M]; // Array of child pointers
    int num_keys;                 // Current number of keys in the node
    int is_leaf;                  // 1 if Leaf node, 0 otherwise
} BTreeNode;

BTreeNode* createNode(int is_leaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->num_keys = 0;
    newNode->is_leaf = is_leaf;
    for (int i = 0; i < M; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Display keys in a node
void displayNode(BTreeNode* node) {
    printf("[ ");
    for (int i = 0; i < node->num_keys; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("]");
}

int main() {
    printf("--- B-Tree / M-Way Tree Concept Test Cases ---\n\n");
    printf("Order (M) = %d\n", M);
    printf("Max Keys per Node = %d\n", M - 1);
    printf("Max Children per Node = %d\n\n", M);
    
    // Creating a mock root node and populating it to show the structure
    BTreeNode* root = createNode(0);
    root->keys[0] = 20;
    root->keys[1] = 40;
    root->num_keys = 2; // Root has 2 keys, meaning it divides data into 3 ranges:
                        // <20, between 20 & 40, >40
                        
    // Child 1 (values < 20)
    BTreeNode* child1 = createNode(1);
    child1->keys[0] = 10;
    child1->keys[1] = 15;
    child1->num_keys = 2;
    
    // Child 2 (values between 20 and 40)
    BTreeNode* child2 = createNode(1);
    child2->keys[0] = 30;
    child2->num_keys = 1;
    
    // Child 3 (values > 40)
    BTreeNode* child3 = createNode(1);
    child3->keys[0] = 50;
    child3->keys[1] = 60;
    child3->num_keys = 2;
    
    root->children[0] = child1;
    root->children[1] = child2;
    root->children[2] = child3;
    
    printf("Simulated B-Tree Node Structure:\n");
    printf("          ");
    displayNode(root);
    printf("\n         /      |      \\\n");
    displayNode(child1);
    printf("  ");
    displayNode(child2);
    printf("  ");
    displayNode(child3);
    printf("\n");
    
    return 0;
}
