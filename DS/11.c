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
/*
Depth-First Search (DFS):

1. Function Definition: void DFS(int adj[MAX][MAX], int visit[], int vertex, int n)

2. Initialize Visit Status: Set visit[vertex] to 1 to mark the current vertex as visited.

3. Print Current Vertex: Print the value of the current vertex.

4. Traverse Neighbors: For each vertex adjacent to the current vertex:
   - If the adjacent vertex is not visited (`!visit[i]`) and there exists a connection (`adj[vertex][i] == 1`):
      - Recursively call DFS for the adjacent vertex.

Breadth-First Search (BFS):

1. Function Definition: void BFS(int adj[MAX][MAX], int visit[], int start, int n)

2. Initialize Queue: Create a queue data structure (queue[MAX]) to store vertices to be visited. Initialize front and rear to -1.

3. Enqueue Starting Vertex: Add the starting vertex to the queue and mark it as visited.

4. While Queue is Not Empty:
   - Dequeue a vertex from the front of the queue.
   - Print the dequeued vertex.
   - For each vertex adjacent to the dequeued vertex:
      - If the adjacent vertex is not visited and there exists a connection:
         - Enqueue the adjacent vertex.
         - Mark it as visited.

Main Function:

1. Input: 
   - Get the number of cities (`n`).
   - Input the adjacency matrix representing connections between cities.

2. DFS Traversal:
   - Input the starting city for traversal.
   - Initialize the visited array.
   - Call DFS with the starting city.

3. Reset Visited Array:
   - Reset the visited array to 0 for the next traversal.

4. BFS Traversal:
   - Input the starting city for traversal.
   - Initialize the visited array.
   - Call BFS with the starting city.
*/