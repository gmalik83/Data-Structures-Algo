#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

// Ways to Reach N,N

// -1 Blockage or Dead-end . Direction Allowed = DOWN , RIGHT

// Return Count of Posssible Path from 0,0 to R-1,C-1
int countPaths(int maze[][C])
{
    // If initial is blocked no way to move anywhere
    if (maze[0][0] == -1)
        return 0;

    // Initializing the leftmost column
    for (int i = 0; i < R; i++)
    {
        if (maze[i][0] == 0)
            maze[i][0] = 1;
        else
            break;
    }
    for (int i = 1; i < C; i++)
    {
        if (maze[0][i] == 0)
            maze[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            // Blockage then ignore
            if (maze[i][j] == -1)
                continue;
            // If We can move DOWN
            if (maze[i - 1][j] > 0)
                maze[i][j] += maze[i - 1][j];
            if (maze[i][j - 1] > 0)
                maze[i][j] += maze[i][j - 1];
        }
    }
    return (maze[R - 1][C - 1] > 0) ? maze[R - 1][C - 1] : 0;
}

int main()
{
    int maze[R][C] = {
        {0, 0, 0, 0},
        {0, -1, 0, 0},
        {-1, 0, 0, 0},
        {0, 0, 0, 0}};
    cout << "Number of Ways to Reach : "<< countPaths(maze)<<endl;

    return 0;
}