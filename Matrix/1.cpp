#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 6

// Print Matrix in Spiral Form

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

int main()
{
    int a[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    // Function Call
    spiralPrint(R, C, a);

    return 0;
}