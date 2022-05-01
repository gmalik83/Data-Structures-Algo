#include <bits/stdc++.h>
using namespace std;
// Maximum Stock One can Buy

// Return the Maximum Stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> v;
    // Make pair of Product Cost and Number of Day
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(price[i], i + 1));
    // Sort the Vector Pair
    sort(v.begin(), v.end());

    // Calculating Maximum Number of Stock Count
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second, (k / v[i].first));
    }
    return ans;
}

int main()
{
    int price[] = {10, 7, 19};
    int n = 3;
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}