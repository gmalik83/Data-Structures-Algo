#include <bits/stdc++.h>
using namespace std;
int getMinDifference(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int minEle, maxEle;
    int result = arr[n - 1] - arr[0];
    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] >= k && arr[n - 1] >= k)
        {
            maxEle = max(arr[i - 1] + k,
                         arr[n - 1] - k);

            minEle = min(arr[0] + k, arr[i] - k);

            result = min(result, maxEle - minEle);
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 15, 10};
    int n = 3;
    int k = 6;
    cout << getMinDifference(arr, n, k);
    return 0;
}