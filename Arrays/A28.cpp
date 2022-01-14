#include <bits/stdc++.h>
using namespace std;
// Maximum Product Subarray
/*
    Solutions: 
    1. Naive : Consider all subarrays and keep max ans 

*/
// Return the product of maximum product subarray
int maxSubarrayProduct(int arr[], int n)
{
    // Initialize result
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        // Traverse Current Subarray
        for (int j = i + 1; j < n; j++)
        {
            // Update result to keep maximum product
            res = max(res, mul);
            mul *= arr[j];
        }
        // Update result for n-1 index
        res = max(res, mul);
    }
    return res;
}
// This will be a O(N2) and O(1) complexity as both loop for  every element

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}