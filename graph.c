#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node* adjList[MAX];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = -1, rear = -1;
    visited[startVertex] = 1;
    queue[++rear] = startVertex;
    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

void DFSUtil(struct Graph* graph, int currentVertex, int visited[]) {
    visited[currentVertex] = 1;
    printf("%d ", currentVertex);
    struct Node* temp = graph->adjList[currentVertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    DFSUtil(graph, startVertex, visited);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        printf("Enter edge %d : ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    int startVertex;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);
    printf("BFS traversal starting from vertex %d: ", startVertex);
    BFS(graph, startVertex);
    printf("\n");
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex);
    printf("\n");
    return 0;
}

