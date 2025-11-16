#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX];
    bool visited[MAX];
} Graph;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS_Recursive(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = true;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS_Recursive(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void DFS_NonRecursive(Graph* graph, int startVertex) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = false;

    stack[++top] = startVertex;

    while (top != -1) {
        int vertex = stack[top--];

        if (!graph->visited[vertex]) {
            printf("%d ", vertex);
            graph->visited[vertex] = true;
        }

        Node* temp = graph->adjLists[vertex];
        while (temp) {
            if (!graph->visited[temp->vertex]) {
                stack[++top] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

void BFS(Graph* graph, int startVertex) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = false;

    graph->visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front != rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* temp = graph->adjLists[vertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

void BFS_Recursive(Graph* graph, int queue[], int* front, int* rear) {
    if (*front == *rear)
        return;

    int vertex = queue[(*front)++];
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            graph->visited[adjVertex] = true;
            queue[(*rear)++] = adjVertex;
        }
        temp = temp->next;
    }

    BFS_Recursive(graph, queue, front, rear);
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("DFS (Recursive): ");
    DFS_Recursive(graph, 0);
    printf("\n");

    printf("DFS (Non-Recursive): ");
    DFS_NonRecursive(graph, 0);
    printf("\n");

    printf("BFS (Non-Recursive): ");
    BFS(graph, 0);
    printf("\n");

    // Recursive BFS demo
    int queue[MAX];
    int front = 0, rear = 0;
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = false;
    graph->visited[0] = true;
    queue[rear++] = 0;
    printf("BFS (Recursive): ");
    BFS_Recursive(graph, queue, &front, &rear);
    printf("\n");

    return 0;
}
