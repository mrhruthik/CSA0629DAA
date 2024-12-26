#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void floydWarshall(int graph[4][4], int V) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("All Pairs Shortest Distances:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[4][4] = {
        {0, 8, 7, 8},
        {9, 0, 11, 12},
        {10, 9, 0, 11},
        {8, 10, 11, 0}
    };
    int V = 4;
    floydWarshall(graph, V);
    return 0;
}