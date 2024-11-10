#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Create a new graph node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with given vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS) traversal
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX];
    int front = 0, rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int connectedVertex = temp->vertex;

            if (graph->visited[connectedVertex] == 0) {
                graph->visited[connectedVertex] = 1;
                queue[++rear] = connectedVertex;
            }
            temp = temp->next;
        }
    }
}

// Reset visited array for new traversal
void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// Main function to demonstrate graph traversals
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("DFS traversal starting from vertex 0: ");
    DFS(graph, 0);

    resetVisited(graph);
    printf("\nBFS traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}

