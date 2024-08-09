// a. Design and implement C Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.

/*
Data Structures:

dist[][]: Matrix storing shortest distances between every pair of vertices. Initialized to the adjacency matrix of the graph.

Floyd-Warshall Algorithm:

Initialization: dist[i][j] holds the shortest known distance from vertex i to vertex j.
Update Distances: For each possible intermediate vertex k, update the shortest path between every pair of vertices (i, j) by considering if the path through k is shorter.

Main Function:

The dist matrix initializes the graph with distances where INF denotes no direct edge.
floydWarshall() computes the shortest paths between all pairs of vertices.
*/

#include <stdio.h>

#define MAX 100
#define INF 9999

void floydWarshall(int n, int dist[MAX][MAX])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 4; // Number of vertices
    int dist[MAX][MAX] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    floydWarshall(n, dist);
    return 0;
}
