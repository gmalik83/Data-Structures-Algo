#include <bits/stdc++.h>
using namespace std;
#define size 10
#define target 100
// Declare Global DP for Top Down
int dp[size + 1][target + 1];
bool isSubset(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    // Check in DP first
    if (dp[n][sum] != -1)
        return dp[n][sum];
    // If Last element is greater than sum , we can ignore it
    if (set[n - 1] > sum)
        return dp[n][sum] = isSubset(set, n - 1, sum);
    // Check if sum is obtained by including or Excluding element
    return dp[n][sum] = isSubset(set, n - 1, sum - set[n - 1]) || isSubset(set, n - 1, sum);
}
int main()
{
    int set[] = {1, 2, 3, 4, 5};
    memset(dp, -1, sizeof(dp));
    if (isSubset(set, 5, -1) == 1)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}