#include <stdio.h>
#include <stdlib.h>

/*
 * Graphs: Representation (Adjacency Matrix & Adjacency List)
 */

#define V 4 // Number of vertices

// --- 1. Adjacency Matrix ---
void initMatrix(int arr[][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdgeMatrix(int arr[][V], int src, int dest) {
    arr[src][dest] = 1;
    arr[dest][src] = 1; // Undirected graph
}

void printMatrix(int arr[][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// --- 2. Adjacency List ---
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

typedef struct {
    int numVertices;
    AdjList* array;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdgeList(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src (undirected)
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printList(Graph* graph) {
    printf("\nAdjacency List:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* pCrawl = graph->array[v].head;
        printf("Vertex %d ", v);
        while (pCrawl) {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    printf("--- Graph Representations Test Cases ---\n\n");

    /*
     * Graph:
     * 0 --- 1
     * | \   |
     * |  \  |
     * 3 --- 2
     */

    // Test Matrix
    int adjMatrix[V][V];
    initMatrix(adjMatrix);
    addEdgeMatrix(adjMatrix, 0, 1);
    addEdgeMatrix(adjMatrix, 0, 2);
    addEdgeMatrix(adjMatrix, 0, 3);
    addEdgeMatrix(adjMatrix, 1, 2);
    addEdgeMatrix(adjMatrix, 2, 3);
    printMatrix(adjMatrix);

    // Test List
    Graph* graph = createGraph(V);
    addEdgeList(graph, 0, 1);
    addEdgeList(graph, 0, 2);
    addEdgeList(graph, 0, 3);
    addEdgeList(graph, 1, 2);
    addEdgeList(graph, 2, 3);
    printList(graph);

    return 0;
}
