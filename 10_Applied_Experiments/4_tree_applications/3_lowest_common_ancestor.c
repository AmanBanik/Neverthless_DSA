#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Trees - Lowest Common Ancestor (LCA) of a Binary Tree
 * Find the lowest common ancestor node of two given nodes in the tree.
 *
 * Approach: Recursive DFS
 * If current node is p or q, return current node.
 * Look in left and right subtrees. If both return non-null, current node is LCA!
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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p, q);
    
    // If both left and right return a node, root is the LCA
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }
    
    // Otherwise return the non-null child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    printf("--- Lowest Common Ancestor Test Cases ---\n\n");
    
    /*
     * Tree:
     *        3
     *      /   \
     *     5     1
     *    / \   / \
     *   6   2 0   8
     *      / \
     *     7   4
     */
    Node* root = createNode(3);
    Node* p = root->left = createNode(5);
    Node* q = root->right = createNode(1);
    root->left->left = createNode(6);
    Node* node2 = root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    node2->left = createNode(7);
    Node* node4 = node2->right = createNode(4);
    
    // LCA of 5 and 1 should be 3
    Node* lca1 = lowestCommonAncestor(root, p, q);
    printf("LCA of 5 and 1: %d (Expected: 3)\n", lca1->data);
    
    // LCA of 5 and 4 should be 5
    Node* lca2 = lowestCommonAncestor(root, p, node4);
    printf("LCA of 5 and 4: %d (Expected: 5)\n", lca2->data);
    
    return 0;
}
