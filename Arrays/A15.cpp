#include <bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
{
    // If source and destination are same
    if (n == 1)
        return 0;
    // Traverse all points reachable from arr[l] to arr[h]
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    cout << "Minimum jumps is: " << minJumps(arr, n);
    return 0;
}