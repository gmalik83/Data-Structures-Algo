#include <bits/stdc++.h>
using namespace std;
bool isSubset(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    // If Last element is greater than sum , we can ignore it
    if (set[n - 1] > sum)
        return isSubset(set, n - 1, sum);
    // Check if sum is obtained by including or Excluding element
    return isSubset(set, n - 1, sum - set[n - 1]) || isSubset(set, n - 1, sum);
}
int main()
{
    int set[] = {1, 2, 3, 4, 5};
    if (isSubset(set, 5, 0) == 1)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}