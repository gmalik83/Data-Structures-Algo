#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    // Find Min number of Coins with sum > sum/2
    sum = sum / 2;
    sort(arr, arr + n);
    int count = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += arr[i];
        count++;
        if (ans > sum)
            break;
    }
    cout << count;

    return 0;
}