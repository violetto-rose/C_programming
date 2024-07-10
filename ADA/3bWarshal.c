// b. Design and implement C Program to find the transitive closure using Warshal's algorithm.
#include <stdio.h>

#define V 4

// Function to print the transitive closure matrix
void printTransitiveClosure(int graph[][V])
{
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to find transitive closure using Warshall's algorithm
void transitiveClosure(int graph[][V])
{
    int reach[V][V];
    // Initialize the reach[][] matrix to the given graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }
    // Warshall's algorithm to find transitive closure
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    // Print the transitive closure matrix
    printTransitiveClosure(reach);
}

int main()
{
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}};
    transitiveClosure(graph);
    return 0;
}
