#include <stdio.h>
#include <stdbool.h>
#define INF 999999

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int graph[4][4], int n, int start) {
    int dist[n];
    int parent[n];
    bool visited[n];
    int i, j, min_dist, u;
    
    // Initialize all distances to infinity, visited to false, and parent to -1
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    // Distance from starting vertex to itself is 0
    dist[start] = 0;
    
    // Find shortest path for all vertices
    for (i = 0; i < n-1; i++) {
        // Choose the vertex with minimum distance
        min_dist = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        
        // Mark the chosen vertex as visited
        visited[u] = true;
        
        // Update the distances of its neighboring vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INF && dist[u]+graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
    
    // Print the shortest distances and paths from the starting vertex
    printf("Shortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        printf("%d: %d\tPath: ", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int n, i, j, start;
    n=4;
    int graph[4][4]={{0,1,3,0},
                     {0,0,1,10},
                     {0,0,0,4},
                     {0,0,0,0}};
    start=0;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &n);
    // printf("Enter the adjacency matrix:\n");
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
    //         scanf("%d", &graph[i][j]);
    //     }
    // }
    // printf("Enter the starting vertex: ");
    // scanf("%d", &start);
    dijkstra(graph, n, start);
    return 0;
}
