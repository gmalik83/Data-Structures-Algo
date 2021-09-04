#include <bits/stdc++.h>
using namespace std;
/*
    Direction : Right   , Right Up Right Down
    Right row,col+1;
    Right-Up : row-1,col+1;
    Right-DOwn : row+1,col+1;

    Starting Point - Any Row of First Column


*/
#define MAX 100

int getMaxGold(int gold[][MAX], int m, int n)
{
    // Table Store intermediate Values
    int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));

    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            // Gold in Right
            int right = (col == n - 1) ? 0 : goldTable[row][col + 1];
            // GOld in Right Up
            int right_up = (row == 0 || col == n - 1) ? 0 : goldTable[row - 1][col + 1];
            // Gold in RIght Down
            int right_down = (row == m - 1 || col == n - 1) ? 0 : goldTable[row + 1][col + 1];
            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
        }
    }
    int res = goldTable[0][0];
    for (int i = 1; i < m; i++)
        res = max(res, goldTable[i][0]);

    return res;
}
int main()
{
    int n = 3, m = 3;
    int mat[MAX][MAX] = {{1, 3, 3},
                         {2, 1, 4},
                         {0, 6, 4}};
    cout << getMaxGold(mat, m, n) << endl;

    return 0;
}