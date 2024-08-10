// Design and implement C Program to obtain the Topological ordering of vertices in a given digraph.

/*
Data Structures:

stack[]: Used to store the vertices in topological order.
visited[]: Array to track visited vertices during DFS.

Topological Sorting:

DFS Utility: The topologicalSortUtil() function performs a DFS starting from a given vertex v. After visiting all its adjacent vertices, the vertex v is pushed onto the stack.
Topological Sort: The topologicalSort() function iterates over all vertices, performing DFS for each unvisited vertex. The vertices are then popped from the stack to produce the topological order.

Main Function:

The adj matrix represents the adjacency matrix of the directed graph.
The topologicalSort() function is called to generate the topological order of the vertices.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void topologicalSortUtil(int v, int visited[], int adj[MAX][MAX], int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, adj, n);
        }
    }

    push(v);
}

void topologicalSort(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, adj, n);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int n = 6; // Number of vertices
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(adj, n);
    return 0;
}
