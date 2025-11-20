#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct Edge {
    int start_vert;
    int end_vert;
    int weight;
} Edge;

typedef struct Graph {
    int vertices;
    int edges;
    Node **adj_list; // 2D array, list pointing to another list
} Graph;

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

QNode *front, *rear;

typedef struct StNode {
    char data;
    struct StNode* next;
} StNode;

StNode *top;

// Queue operations start

void enqueue(int x) {
    QNode *q;
    q = (QNode*)malloc(sizeof(QNode));
    if(q==NULL){
        printf("Queue is Full");
    }else{
        q->data=x;
        q->next=NULL;
        if(front==NULL){
            front = rear = q;
        }
        else {
        rear->next=q;
        rear = q;
        }
    }
    return;

}

int dequeue() {
    int x = -1;

    if(front == NULL){
        printf("Queue is empty");
    }else{
        QNode *p;
        p = front;
        front=front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display() {
    QNode *p;
    p = front;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isEmpty () {
    return front == NULL;
}

// Queue operations end

// Stack operations start

void push (int x) { // insert
    StNode *newStNode = (StNode*)malloc(sizeof(StNode));

    if (newStNode == NULL) {
        return;
    }
    else { 
        newStNode->data = x;
        newStNode->next = top;
        top = newStNode;
    }
}

int pop () { // delete
    int x = -1;

    if (top == NULL)
        return x;
    else {
        StNode *temp = top;
        x = top->data;
        top = top->next;
        free(temp);
    }
    return x;
}

int isEmptyStack () {
    return top == NULL;
}

// Stack operations end

void init (Graph *graph, int vert) {
    graph->vertices = vert;
    graph->edges = 0;

    graph->adj_list = (Node **)malloc(vert * sizeof(Node *));

    for (int i = 0; i < vert; i++)
        graph->adj_list[i] = NULL;
}

Node *create_node (int vert, int weight) {
    Node *nnode = (Node *)malloc(sizeof(Node));
    nnode->vertex = vert;
    nnode->weight = weight;
    nnode->next = NULL;

    return nnode;
}

void addEdge (Graph *graph, int src, int dest, int weight) {
    Node *nnode = create_node(dest, weight);
    nnode->next = graph->adj_list[src];
    graph->adj_list[src] = nnode;
    // since undirected
    nnode = create_node(src, weight);
    nnode->next = graph->adj_list[dest];
    graph->adj_list[dest] = nnode;

    graph->edges++;
}

void removeEdge (Graph *graph, int src, int dest) {
    Node *temp = graph->adj_list[src];
    Node *prev = NULL;

    while (temp && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp)
       return;
    if (!prev) {
        graph->adj_list[src] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    // since undirected
    Node *temp2 = graph->adj_list[dest];
    Node *prev2 = NULL;

    while (temp2 && temp2->vertex != src) {
        prev2 = temp2;
        temp2 = temp2->next;
    }

    if (!temp2)
       return;
    if (!prev2) {
        graph->adj_list[dest] = temp2->next;
    } else {
        prev2->next = temp2->next;
    }

    free(temp2);
}

void print (Graph graph) {
    for (int i = 0; i < graph.vertices; i++) {
        Node *temp = graph.adj_list[i];
        printf("%d: ", i); // print index
        while (temp) {
            printf("%d(%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void createGraph (Graph *graph, char *filename) {
    FILE *fp = fopen (filename, "r");

    if (!fp) {
        perror("Error opening file: ");
        return;
    }

    int vertices, weight;
    fscanf(fp, "%d", &vertices);

    init(graph, vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            fscanf(fp, "%d", &weight);
            if (weight && i < j)
                addEdge(graph, i, j, weight);
        }
    }
    fclose(fp);
}

void bfs (Graph graph, int start_vert) { // Uses Queue
    front = rear = NULL;
    int *visited = (int *)calloc(graph.vertices, sizeof(int)); // calloc initializes with 0

    enqueue(start_vert);
    visited[start_vert] = 1;

    while (!isEmpty()) {
        int current_vert = dequeue();

        printf("%d ", current_vert);

        Node *temp = graph.adj_list[current_vert];

        while (temp) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
}

void dfs_helper (Graph graph, int *visited, int current_vert) {
    visited[current_vert] = 1;
    printf("%d ", current_vert);

    Node *temp = graph.adj_list[current_vert];

    while (temp) {
        if (!visited[temp->vertex])
            dfs_helper(graph, visited, temp->vertex);
        temp = temp->next;
    }
}

void dfs (Graph graph, int start_vert) {
    int *visited = (int *)calloc(graph.vertices, sizeof(int));

    dfs_helper(graph, visited, start_vert);

    for (int i = 0; i < graph.vertices; i++) {
        if (!visited[i])
            dfs_helper(graph, visited, i);
    }
    printf("\n");
    free(visited);
}

void iterative_dfs (Graph graph, int start_vert) { // Uses Stack
    top = NULL;
    int *visited = (int *)calloc(graph.vertices, sizeof(int));

    push(start_vert);

    while (!isEmptyStack()) {
        int current_vert = pop();

        if (!visited[current_vert]) {
            printf("%d ", current_vert);
            visited[current_vert] = 1;
        }
        // push all adjacent vertices onto the stack
        Node *temp = graph.adj_list[current_vert];
        while (temp) {
            if (!visited[temp->vertex])
                push(temp->vertex);
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
}

// void hasCycle (Graph graph) {
//     top = NULL;
//     int *visited = (int *)calloc(graph.vertices, sizeof(int));
//     int *parent = (int *)calloc(graph.vertices, sizeof(int));

//     for (int i = 0; i < graph.vertices; i++)
//         parent[i] = -1;
    
    
// }

void freeGraph (Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->adj_list[i];
        while (temp) {
            Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->adj_list);
    graph->vertices = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Graph g;

    createGraph(&g, argv[1]);
    print(g);

    printf("BFS: \n");
    bfs(g, 2);

    printf("DFS: \n");
    iterative_dfs(g, 2);
    freeGraph(&g);
    return 0;
}