#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string str1 = "ABCDEFG";
    string str2 = "ACDE";
    cout << LCS(str1, str2, 7, 4);
}