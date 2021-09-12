#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (str1[m - 1] == str2[n - 1])
        return dp[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return dp[m][n] = max(LCS(str1, str2, m, n - 1), LCS(str1, str2, m - 1, n));
}
int main()
{
    string str1 = "ABCDEFG";
    string str2 = "ACDE";
    memset(dp, -1, sizeof(dp));
    cout << LCS(str1, str2, 7, 4);
}