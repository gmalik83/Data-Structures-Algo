#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

bool isInbound(int i, int j)
{
    if (i < 0 || i >= R || j < 0 || j >= C)
        return false;

    return true;
}

// Print Matrix in Spiral Form
/*
void spiralPrint(int m, int n, int a[R][C])
{
    // Initialize different values
    int i, k = 0, l = 0;
    while (k < m && l < n)
    {
        // Print first row from remaining rows
        for (i = l; i < n; i++)
            cout << a[k][i] << " ";
        k++;
        // Print Last Column
        for (i = k; i < m; i++)
            cout << a[i][n - 1] << " ";
        n--;
        // Print last Row from remaining rows
        if (k < m)
        {
            for (i = n - 1; i >= l; i--)
                cout << a[m - 1][i] << " ";
            m--;
        }
        // Print the first column
        if (l < n)
        {
            for (i = m - 1; i >= k; i--)
                cout << a[i][l] << " ";
            l++;
        }
    }
}
*/
// CHeck if position is Blocked
bool isBlocked(int matrix[R][C], int i, int j)
{
    if (!isInbound(i, j))
        return true;
    if (matrix[i][j] == -1)
        return true;

    return false;
}
void spirallyDFSTravserse(int matrix[R][C], int i, int j,
                          int dir, vector<int> &res)
{
    if (isBlocked(matrix, i, j))
        return;
    bool allBlocked = true;

    for (int k = -1; k <= 1; k += 2)
    {
        allBlocked = allBlocked && isBlocked(matrix, k + i, j) && isBlocked(matrix, i, j + k);
    }
    res.push_back(matrix[i][j]);
    matrix[i][j] = -1;
    if (allBlocked)
    {
        return;
    }

    // dir: 0 - right, 1 - down, 2 - left, 3 - up
    int nxt_i = i;
    int nxt_j = j;
    int nxt_dir = dir;
    if (dir == 0)
    {
        if (!isBlocked(matrix, i, j + 1))
        {
            nxt_j++;
        }
        else
        {
            nxt_dir = 1;
            nxt_i++;
        }
    }
    else if (dir == 1)
    {
        if (!isBlocked(matrix, i + 1, j))
        {
            nxt_i++;
        }
        else
        {
            nxt_dir = 2;
            nxt_j--;
        }
    }
    else if (dir == 2)
    {
        if (!isBlocked(matrix, i, j - 1))
        {
            nxt_j--;
        }
        else
        {
            nxt_dir = 3;
            nxt_i--;
        }
    }
    else if (dir == 3)
    {
        if (!isBlocked(matrix, i - 1, j))
        {
            nxt_i--;
        }
        else
        {
            nxt_dir = 0;
            nxt_j++;
        }
    }
    spirallyDFSTravserse(matrix, nxt_i, nxt_j, nxt_dir,
                         res);
}
// Traverse Spirally
vector<int> spirallyTraverse(int matrix[R][C])
{
    vector<int> res;
    spirallyDFSTravserse(matrix, 0, 0, 0, res);
    return res;
}

int main()
{
    /*
    int a[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    // Function Call
    spiralPrint(R, C, a);
    */
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    // Function call
    vector<int> res = spirallyTraverse(a);
    int size = res.size();
    for (int i = 0; i < size; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}