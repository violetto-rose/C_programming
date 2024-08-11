// b. Design and implement C Program to find the transitive closure using Warshal's algorithm.#include <stdio.h>

/*
Input: The reach[][] matrix represents the adjacency matrix of the graph, where 1 indicates a direct edge between vertices, and 0 indicates no direct edge.

Warshall’s Algorithm:

It iteratively checks if there is a path from vertex i to vertex j through some intermediate vertex k.
If such a path exists, it updates the reach[i][j] to 1.
Output: The transitive closure matrix, which shows whether there is a path between every pair of vertices.
*/

#include <stdio.h>

#define MAX 100

void warshall(int n, int reach[MAX][MAX]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Number of vertices
    int reach[MAX][MAX] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    warshall(n, reach);
    return 0;
}