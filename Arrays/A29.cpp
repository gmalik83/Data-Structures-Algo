#include <bits/stdc++.h>
using namespace std;
// Longest Consecutive Elements
/*
    Problem : Increasing Order longest length
    1. Naive Method : Sort array and find length of consecutive

*/
// Return Length of longest contiguos subsequence
int findLongestSubsequence(int arr[], int n)
{
    int ans = 0, count = 0;
    // sort the array
    sort(arr, arr + n);

    vector<int> v;
    v.push_back(arr[0]);
    // Insert repeated element only once
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // Find Maximum length by traversing the array
    for (int i = 0; i < v.size(); i++)
    {
        // Check for increasing order
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        else
            // reset the count
            count = 1;
        // Update answer
        ans = max(ans, count);
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 2, 3};
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestSubsequence(arr, n);

    return 0;
}