#include <bits/stdc++.h>
using namespace std;
// Smallest length of subarray with sum greater than x
int smallestSubWithSum(int arr[], int n, int x)
{
    // initialize length of smallest subarray as n+1
    int min_len = n + 1;
    // Consider every element as starting point of subarray
    for (int start = 0; start < n; start++)
    {
        int curr_sum = arr[start];
        // If first element is itself greater
        if (curr_sum > x)
            return 1;
        // Try different points for current start
        for (int end = start + 1; end < n; end++)
        {
            // Add last element to current sum
            curr_sum += arr[end];
            // Update result if any changes
            if (curr_sum > x && (end - start + 1) < min_len)
                min_len = end - start + 1;
        }
    }
    return min_len;
}
int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = 6;
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n" : cout << res1 << endl;

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = 5;
    x = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2 + 1) ? cout << "Not possible\n" : cout << res2 << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = 10;
    x = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3 + 1) ? cout << "Not possible\n" : cout << res3 << endl;

    return 0;
}