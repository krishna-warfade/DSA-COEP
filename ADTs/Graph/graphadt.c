#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Graph {
    int vertices;
    int edges;
    int **adj_mat; // 2D array
} Graph;

typedef struct Edge {
    int start_vert;
    int end_vert;
    int weight;
} Edge;

void init (Graph *graph, int vert) {
    graph->vertices = vert;
    graph->edges = 0;
    graph->adj_mat = (int **)malloc(vert * sizeof(int)); // allocates garbage memory

    for (int i = 0; i < vert; i++) {
        graph->adj_mat[i] = (int *)calloc(vert, sizeof(int)); // allocates 0 0 0 0 0 ... 0   (vert times), for one row of adj_mat
    }
}

void addEdge (Graph *graph, int src, int dest, int weight) {
    graph->adj_mat[src][dest] = weight;
    graph->adj_mat[dest][src] = weight;
    graph->edges++;
}

void removeEdge (Graph *graph, int src, int dest) {
    graph->adj_mat[src][dest] = 0;
    graph->adj_mat[dest][src] = 0;
    graph->edges--;
}

void print_adj_mat (Graph graph) {
    for (int i = 0; i < graph.vertices; i++) {
        for (int j = 0; j < graph.vertices; j++)
            printf("%d ", graph.adj_mat[i][j]);
        printf("\n");
    }
}

void createGraph (Graph *graph, char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        perror("Error opening file: ");
        return;
    }
    int vertices, temp;

    fscanf(fp, "%d", &vertices);

    init(graph, vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            fscanf(fp, "%d", &temp);
            if (temp && i <= j)
                addEdge(graph, i, j, temp);
        }
    }
    fclose(fp);
}

void freeGraph (Graph *graph) {
    for (int i = 0; i < graph->vertices; i++)
        free(graph->adj_mat[i]);
    free(graph->adj_mat);
    graph->adj_mat = NULL;
    graph->vertices = 0;
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Graph g;
    createGraph(&g, argv[1]);
    print_adj_mat(g);
    printf("\n");

    freeGraph(&g);
    return 0;
}
