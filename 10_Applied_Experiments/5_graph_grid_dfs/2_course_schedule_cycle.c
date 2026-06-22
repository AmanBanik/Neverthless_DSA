#include <stdio.h>
#include <stdlib.h>

/*
 * Applied: Graphs - Cycle Detection (Course Schedule concept)
 * Determine if a directed graph has a cycle.
 *
 * Approach: DFS with 3 States (White, Gray, Black)
 * 0 = Unvisited
 * 1 = Visiting (Currently in our DFS recursion stack)
 * 2 = Visited (Completely processed)
 * If we encounter a node in state 1 during our DFS, we have found a cycle!
 */

#define V 4

// Returns 1 if cycle exists, 0 otherwise
int hasCycleDFS(int curr, int adjMatrix[V][V], int state[]) {
    state[curr] = 1; // Mark as visiting
    
    for (int i = 0; i < V; i++) {
        if (adjMatrix[curr][i] == 1) { // If there's a directed edge
            if (state[i] == 1) {
                return 1; // CYCLE FOUND!
            }
            if (state[i] == 0 && hasCycleDFS(i, adjMatrix, state)) {
                return 1;
            }
        }
    }
    
    state[curr] = 2; // Mark as completely visited
    return 0;
}

int canFinishAllCourses(int adjMatrix[V][V]) {
    int state[V] = {0};
    
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (hasCycleDFS(i, adjMatrix, state)) {
                return 0; // False, cannot finish courses because of a cycle
            }
        }
    }
    return 1; // True, no cycle
}

int main() {
    printf("--- Directed Graph Cycle Detection Test Cases ---\n\n");
    
    // Graph 1: 0 -> 1 -> 2 -> 3 (No Cycle)
    int graphNoCycle[V][V] = {0};
    graphNoCycle[0][1] = 1;
    graphNoCycle[1][2] = 1;
    graphNoCycle[2][3] = 1;
    
    printf("Test 1 (No Cycle):\n");
    if (canFinishAllCourses(graphNoCycle)) printf("Result: Can finish! (No Cycle)\n\n");
    else printf("Result: Cannot finish! (Cycle Detected)\n\n");
    
    // Graph 2: 0 -> 1 -> 2 -> 1 (Cycle at 1-2)
    int graphCycle[V][V] = {0};
    graphCycle[0][1] = 1;
    graphCycle[1][2] = 1;
    graphCycle[2][1] = 1;
    
    printf("Test 2 (Cycle 1->2->1):\n");
    if (canFinishAllCourses(graphCycle)) printf("Result: Can finish! (No Cycle)\n");
    else printf("Result: Cannot finish! (Cycle Detected)\n");
    
    return 0;
}
