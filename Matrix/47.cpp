#include <bits/stdc++.h>
using namespace std;
// Row with Maximum Number of 1's
// Matrix is Sorted Row Wise
#define R 4
#define C 4

// Function that will return row with Maximum 1's
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1's
    int j, max_row_index = 0;
    j = C - 1;
    for (int i = 0; i < R; i++)
    {
        // Move left until 0 is found
        bool flag = false; // To check whether a row has more 1's than previous row
        while (j >= 0 && mat[i][j] == 1)
        {
            j = j - 1;
            flag = true;
        }
        if (flag)
        {
            max_row_index = i; // Max Row with max 1 is current row
        }
    }
    if (max_row_index == 0 && mat[0][C - 1] == 0)
        return -1;

    return max_row_index;
}

// Driver Code
int main()
{
    bool mat[R][C] = {{0, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

    return 0;
}
