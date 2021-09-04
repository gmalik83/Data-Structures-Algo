#include <bits/stdc++.h>
using namespace std;

int count(int S[], int m, int n)
{
    int dp[n + 1][m];
    // If N is 0;
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;
    int x, y;
    // Fill Rest Up in Bottom Up Manner
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Include S[i]
            x = (i - S[j] >= 0) ? dp[i - S[j]][j] : 0;
            // Exclude S[i]
            y = (j >= 1) ? dp[i][j - 1] : 0;

            dp[i][j] = x + y;
        }
    }
    return dp[n][m - 1];
}

int main()
{
    int n = 4;
    int S[] = {1, 2, 3};
    int m = 3;
    cout << count(S, m, n);
    return 0;
}
