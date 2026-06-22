#include <stdio.h>

/*
 * Advanced DS: Disjoint Set Union (Union-Find)
 * With Path Compression and Union by Rank.
 * Near O(1) amortized time complexity for Find and Union operations.
 */

#define MAX_NODES 10

int parent[MAX_NODES];
int rank[MAX_NODES];

// Initialize each element as its own parent (own set) with rank 0
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with Path Compression
int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    // Path Compression: directly attach node to the root representative
    parent[i] = find(parent[i]); 
    return parent[i];
}

// Union by Rank
void unionSet(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    
    if (root_i != root_j) {
        // Attach smaller rank tree under root of higher rank tree
        if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        } else if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        } else {
            // If ranks are same, attach one to another and increment rank
            parent[root_j] = root_i;
            rank[root_i]++;
        }
        printf("Union completed between %d and %d\n", i, j);
    } else {
        printf("Elements %d and %d are already in the same set!\n", i, j);
    }
}

int main() {
    printf("--- Disjoint Set Union (Union-Find) Test Cases ---\n\n");
    
    int n = 5; // We have elements 0, 1, 2, 3, 4
    makeSet(n);
    printf("Initialized 5 disjoint sets.\n\n");
    
    unionSet(0, 2);
    unionSet(4, 2);
    unionSet(3, 1);
    
    printf("\nChecking connectivity:\n");
    if (find(4) == find(0)) {
        printf("4 and 0 are connected! (Yes, via 2)\n");
    } else {
        printf("4 and 0 are NOT connected.\n");
    }
    
    if (find(1) == find(0)) {
        printf("1 and 0 are connected!\n");
    } else {
        printf("1 and 0 are NOT connected.\n");
    }
    
    printf("\nAttempting to union 4 and 0:\n");
    unionSet(4, 0); // Should detect they are already connected
    
    return 0;
}
