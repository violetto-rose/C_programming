// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm.

/*
Data Structures:

key[]: Used to pick the minimum weight edge in each step. It is initialized to a very large number (infinity).
mstSet[]: Keeps track of vertices included in the Minimum Spanning Tree (MST).
parent[]: Stores the MST.

Prim’s Algorithm:

Initialization: Start with all keys as infinity and mark all vertices as not yet included in the MST.
Select Minimum Edge: Pick the vertex with the minimum key value that has not been included in the MST yet.
Update Keys: After including a vertex in the MST, update the key values of adjacent vertices to reflect the minimum edge weight connecting them to the MST.

Main Function:

The cost matrix defines the graph, where INF represents no direct edge between nodes.
The prim() function is called with the number of vertices and the cost matrix to find the minimum spanning tree.
*/

#include <stdio.h>

#define MAX 100
#define INF 9999

void prim(int n, int cost[MAX][MAX])
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u;

        for (int v = 0; v < n; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], u = v;

        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (cost[u][v] && !mstSet[v] && cost[u][v] < key[v])
                parent[v] = u, key[v] = cost[u][v];
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d    %d\n", parent[i], i, cost[i][parent[i]]);
}

int main()
{
    int n = 4; // Number of vertices
    int cost[MAX][MAX] = {
        {INF, 2, INF, 6},
        {2, INF, 3, 8},
        {INF, 3, INF, 5},
        {6, 8, 5, INF}};

    prim(n, cost);
    return 0;
}
