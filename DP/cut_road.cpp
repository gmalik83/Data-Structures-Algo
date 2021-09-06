#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int prices[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_val = max(max_val, prices[i] + maximumProfit(prices, n - i - 1));
    }
    return max_val;
}

int main()
{

    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << maximumProfit(prices, n);

    return 0;
}