#include <bits/stdc++.h>
using namespace std;

#define N 5
// The function will return maximum value of specific pair
int findMaxValue(int mat[][N])
{
    // Store Maximum Value
    int maxValue = INT_MIN;
    // Consider all possible pairs of mat(c,d)-mat(a,b)
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            for (int d = a + 1; d < N; d++)
                for (int e = b + 1; e < N; e++)
                    if (maxValue < (mat[d][e] - mat[a][b]))
                        maxValue = mat[d][e] - mat[a][b];

    return maxValue;
}

// Drive Program
int main()
{
    int mat[N][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};
    cout << "Maximum Value is "
         << findMaxValue(mat);

    return 0;
}