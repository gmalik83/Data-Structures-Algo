#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int prices[], int n)
{
    int val[n + 1];
    val[0] = 0;
    int i, j, max_val;
    for (i = 1; i <= n; i++)
    {
        max_val = INT_MIN;
        for (j = 0; j < i; j++)
        {
            max_val = max(max_val, prices[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main()
{

    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << maximumProfit(prices, n);

    return 0;
}