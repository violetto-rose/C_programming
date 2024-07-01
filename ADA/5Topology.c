// Design and implement C Program to obtain the Topological ordering of vertices in a given digraph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6 // Number of vertices

// Data structure to represent a graph node
struct GraphNode
{
    int vertex;
    struct GraphNode *next;
};

// Data structure to represent a graph
struct Graph
{
    int numVertices;
    struct GraphNode **adjLists;
    int *indegree;
};

// Function to create a new graph node
struct GraphNode *createNode(int v)
{
    struct GraphNode *newNode = (struct GraphNode *)malloc(sizeof(struct GraphNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct GraphNode **)malloc(vertices * sizeof(struct GraphNode *));
    graph->indegree = (int *)calloc(vertices, sizeof(int)); // Initialize indegree array with 0

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct GraphNode *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->indegree[dest]++;
}

// Function to perform topological sorting
void topologicalSort(struct Graph *graph)
{
    int *indegree = graph->indegree;
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
            visited[i] = true;
        }
    }

    while (front != rear)
    {
        int u = queue[front++];
        printf("%d ", u); // Print the vertex in topological order
        struct GraphNode *temp = graph->adjLists[u];
        while (temp != NULL)
        {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0 && !visited[temp->vertex])
            {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
}

int main()
{
    struct Graph *graph = createGraph(V);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological ordering of vertices: ");
    topologicalSort(graph);

    return 0;
}