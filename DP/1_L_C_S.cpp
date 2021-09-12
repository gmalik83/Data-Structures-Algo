#include <bits/stdc++.h>
using namespace std;
int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (str1[m - 1] == str2[n - 1])
        return 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return max(LCS(str1, str2, m, n - 1), LCS(str1, str2, m - 1, n));
}
int main()
{
    string str1 = "ABCDEFG";
    string str2 = "ACDE";
    cout << LCS(str1, str2, 7, 4);
}