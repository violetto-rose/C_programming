// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph
{
    int V, E;          // V: number of vertices, E: number of edges
    struct Edge *edge; // Array to store edges
};

// Function to create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    // Allocate memory for the graph
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    // Allocate memory for storing edges
    graph->edge = malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find set of an element i (used in union-find)
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    // Path compression
    return find(parent, parent[i]);
}

// Function to perform union of two sets of x and y (used in union-find)
void Union(int parent[], int x, int y) { parent[x] = y; }

// Function to compare two edges according to their weights (used in qsort)
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find Minimum Cost Spanning Tree using Kruskal's algorithm
void KruskalMST(struct Graph *graph)
{
    int V = graph->V, E = graph->E;
    struct Edge result[V]; // Array to store the resultant MST
    int e = 0, i = 0;      // Index variables
    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, E, sizeof(graph->edge[0]), compare);
    int parent[V];
    for (int v = 0; v < V; ++v)
        parent[v] = -1; // Initialize parent array for union-find
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E)
    {
        // Pick the smallest edge
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        // If including this edge doesn't cause cycle, include it in the result
        if (x != y)
        {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    // Print the edges in the constructed MST and calculate minimum cost
    printf("Edges in MST:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
}

int main()
{
    int V, E;
    printf("Enter V and E: ");
    scanf("%d %d", &V, &E);
    // Create graph
    struct Graph *graph = createGraph(V, E);
    printf("Enter edges in format (source destination weight):\n");
    // Input edges
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    // Find Minimum Cost Spanning Tree
    KruskalMST(graph);
    return 0;
}