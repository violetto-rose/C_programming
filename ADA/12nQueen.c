// Design and implement C Program for N Queen's problem using Backtracking.
#include <stdio.h>
#include <stdbool.h>

// Function to print the solution
void printSolution(int N, int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int N, int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N Queen's problem
bool solveNQUtil(int N, int board[N][N], int col)
{
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        if (isSafe(N, board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(N, board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }

    // If the queen cannot be placed in any row in this column col, return false
    return false;
}

// Function to solve the N Queen's problem using backtracking
bool solveNQ(int N)
{
    int board[N][N];

    // Initialize the board with 0s
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;s

    if (solveNQUtil(N, board, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printSolution(N, board);
    return true;
}

int main()
{
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}
