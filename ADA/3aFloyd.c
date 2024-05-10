// a. Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.

#include <stdio.h>
#include <limits.h>

#define V 4         // Number of vertices in the graph
#define INF INT_MAX // Define infinity as the maximum integer value

// Function to print the solution matrix
void printSolution(int dist[][V])
{
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd's algorithm to find all pair shortest paths
void floydWarshall(int graph[][V])
{
    int dist[V][V]; // Output matrix that will have the shortest distances between every pair of vertices

    // Initialize the solution matrix same as input graph matrix. Or we can say dist[i][j] will be the shortest distance between i and j if there is a direct path between them, otherwise INF.
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    // Before start of an iteration, we have shortest distances between all pairs of vertices such that the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
    // After the end of an iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k}.
    for (int k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main()
{
    // Sample graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    // Call the function to find all pair shortest paths
    floydWarshall(graph);

    return 0;
}