/*8) Develop a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS
method.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS(int adj[MAX][MAX], int visit[], int vertex, int n) {
    int i;
    visit[vertex] = 1;
    printf("%d ", vertex);
    
    for (i = 1; i <= n; i++) {
        if (adj[vertex][i] == 1 && !visit[i]) {
            DFS(adj, visit, i, n);
        }
    }
}

void BFS(int adj[MAX][MAX], int visit[], int start, int n) {
    int queue[MAX], front = -1, rear = -1, i;
    
    queue[++rear] = start;
    visit[start] = 1;
    
    while (front != rear) {
        int vertex = queue[++front];
        printf("%d ", vertex);
        
        for (i = 1; i <= n; i++) {
            if (adj[vertex][i] == 1 && !visit[i]) {
                queue[++rear] = i;
                visit[i] = 1;
            }
        }
    }
}

int main() {
    int adj[MAX][MAX], visit[MAX];
    int i, j, n, start;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        visit[i] = 0;
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting city for traversal: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(adj, visit, start, n);
    printf("\n");

    // Resetting visited array
    for (i = 1; i <= n; i++) {
        visit[i] = 0;
    }

    printf("BFS Traversal: ");
    BFS(adj, visit, start, n);
    printf("\n");

    return 0;
}