#include <bits/stdc++.h>
using namespace std;
int dp[101][101];

int MCM(int pi[], int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int k;
    int min = INT_MAX;
    int count = 0;
    for (k = i; k < j; k++)
    {
        count = MCM(pi, i, k) + MCM(pi, k + 1, j) + pi[i - 1] * pi[k] * pi[j];
        if (count < min)
            min = count;
    }
    return dp[i][j] = min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = 5;
    memset(dp, -1, sizeof(dp));
    cout << "Minimum Number of Multiplication is: " << MCM(arr, 1, n - 1);
    return 0;
}