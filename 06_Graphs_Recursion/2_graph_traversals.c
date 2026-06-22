#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Number of vertices

/*
 * Graphs: Traversals (BFS and DFS)
 * Implemented using an Adjacency Matrix
 */

int adjMatrix[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

// --- BFS Implementation (Uses Queue) ---
void BFS(int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    
    printf("BFS Traversal: ");
    
    // Enqueue start vertex
    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    
    while (front < rear) {
        int currVertex = queue[front++];
        printf("%d ", currVertex);
        
        // Enqueue adjacent unvisited vertices
        for (int i = 0; i < MAX; i++) {
            if (adjMatrix[currVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// --- DFS Implementation (Uses Recursion/Stack) ---
int visitedDFS[MAX] = {0};

void DFS(int currVertex) {
    printf("%d ", currVertex);
    visitedDFS[currVertex] = 1;
    
    // Visit unvisited adjacent vertices
    for (int i = 0; i < MAX; i++) {
        if (adjMatrix[currVertex][i] == 1 && !visitedDFS[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("--- Graph Traversals Test Cases ---\n\n");
    /*
     * Adjacency Matrix represents this graph:
     * 0 --- 1 --- 3
     * |           |
     * 2 --------- 4
     *  \_________/
     */
     
    printf("Starting BFS from vertex 0...\n");
    BFS(0);
    
    printf("\nStarting DFS from vertex 0...\n");
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");
    
    return 0;
}
