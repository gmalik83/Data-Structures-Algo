#include <bits/stdc++.h>
using namespace std;
// Maximum Product Subarray
/*
    Solutions: 
    1. Naive : Consider all subarrays and keep max ans  O(N2) . Expected : O(N) and O(1)


*/
// Return the product of maximum product subarray
int maxSubarrayProduct(int arr[], int n)
{
    // Max Product ending at Current position
    int max_ending_here = arr[0];
    // Min product ending ar current position
    int min_ending_here = arr[0];
    // initialize overall max product
    int max_so_far = arr[0];
    /*
        Max product = Max(element , element*max_ending_here , min_ending_here)

    */
    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(min_ending_here, max_ending_here);
    }
    return max_so_far;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}