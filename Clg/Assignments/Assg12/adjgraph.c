#include <stdio.h>

#define MAX 5

void displayGraph(int graph[MAX][MAX], char landmarks[MAX][20], int n) {
    printf("\n--- City Graph (Adjacency Matrix) ---\n\n");
    printf("    ");
    for (int i = 0; i < n; i++)
        printf("%10s", landmarks[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%10s", landmarks[i]);
        for (int j = 0; j < n; j++) {
            printf("%10d", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    char landmarks[MAX][20] = {
        "Station", "Mall", "Hospital", "Park", "School"
    };

    int graph[MAX][MAX] = {
        {0, 5, 7, 0, 0},    // Station connected to Mall(5), Hospital(7)
        {5, 0, 3, 6, 0},    // Mall connected to Hospital(3), Park(6)
        {7, 3, 0, 4, 8},    // Hospital connected to Mall, Park, School
        {0, 6, 4, 0, 2},    // Park connected to School(2)
        {0, 0, 8, 2, 0}     // School connected to Park(2), Hospital(8)
    };

    displayGraph(graph, landmarks, n);
    return 0;
}
