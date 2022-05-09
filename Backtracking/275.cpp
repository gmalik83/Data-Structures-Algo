#include <bits/stdc++.h>
using namespace std;

#define N 4
// Function Prototype
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

// Utility Function To Print Solution Matrix
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << sol[i][j] << " ";
        cout << endl;
    }
}

// Utility Function to check if index is valid for N*N maze
bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    if (solveMazeUtil(maze, 0, 0, sol) == false)
    {
        cout << "No Solution Exist" << endl;
        return false;
    }
    printSolution(sol);
    return true;
}
// Function to Solve Problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if x,y is goal return true
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    // Check if X,Y is Valid
    if (isSafe(maze, x, y) == true)
    {
        // Check if Current Block is already a Part of Solution Block
        if (sol[x][y] == 1)
            return false;
        // Mark X,Y as part of Solution
        sol[x][y] = 1;
        // Move Forward in X Direction
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        // If No Solution Found in X-Direction , then Move in Y Direction
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
        {
            return true;
        }
        // If None Work , then Backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// Driver Function
int main()
{
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    solveMaze(maze);

    return 0;
}