// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.

/*
Find & Union Functions:

find(int i): This function determines the root of the set in which element i is present.
unionSets(int i, int j): This function unites two sets containing elements i and j.

Kruskal’s Algorithm:

Initialization: Start by assuming each vertex is its own parent.
Finding the Minimum Edge: Search for the smallest edge that connects two different sets (i.e., it doesn't form a cycle).
Union of Sets: After finding an edge, unite the sets containing the two vertices of the edge and add the edge to the result.
Termination: The algorithm continues until all vertices are connected (i.e., n-1 edges).

Main Function:

The cost matrix defines the graph, where 9999 represents no direct edge between nodes.
The kruskal() function is called with the number of vertices and the cost matrix to find the minimum spanning tree and its cost.
*/

#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n, int cost[MAX][MAX])
{
    int mincost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0;
    while (edges < n - 1)
    {
        int min = 9999, u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        unionSets(u, v);
        printf("Edge %d:(%d, %d) cost:%d\n", edges++, u, v, min);
        mincost += min;
    }

    printf("Minimum cost = %d\n", mincost);
}

int main()
{
    int n = 4; // Number of vertices
    int cost[MAX][MAX] = {
        {9999, 1, 3, 9999},
        {1, 9999, 3, 6},
        {3, 3, 9999, 4},
        {9999, 6, 4, 9999}};

    kruskal(n, cost);
    return 0;
}
