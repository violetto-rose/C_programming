// Design and implement C Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.

/*
Data Structures:

dist[]: Array to store the shortest distance from the source vertex to each vertex.
visited[]: Array to track which vertices have been processed.

Dijkstra’s Algorithm:

Initialization: Set the distance to the source vertex to 0 and all others to INF. Mark all vertices as unvisited.
Find Minimum Distance: In each iteration, select the vertex with the minimum distance that hasn't been visited yet.
Update Distances: Update the distance of adjacent vertices if a shorter path is found via the current vertex.

Main Function:

The graph matrix represents the adjacency matrix of the graph, where 0 indicates no direct edge between vertices.
dijkstra() function is called with the number of vertices, the graph, and the starting vertex.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int n, int graph[MAX][MAX], int start)
{
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u;

        // Find the vertex with the minimum distance
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        // Update the distance of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main()
{
    int n = 4; // Number of vertices
    int graph[MAX][MAX] = {
        {0, 10, 0, 30},
        {10, 0, 50, 0},
        {0, 50, 0, 20},
        {30, 0, 20, 0}};

    int start = 0; // Starting vertex for Dijkstra's algorithm
    dijkstra(n, graph, start);
    return 0;
}