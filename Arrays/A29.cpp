#include <bits/stdc++.h>
using namespace std;
// Longest Consecutive Elements
/*
    Problem : Increasing Order longest length
    1. Naive Method : Sort array and find length of consecutive O(nlogn) and O(1)
    2. Use Hash . Push all elements in hash and then check for starting point and length of the subsequence 


*/
// Return Length of longest contiguos subsequence
int findLongestSubsequence(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
    // Hash all array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    // Check all possible length from start and then update optimal length
    for (int i = 0; i < n; i++)
    {
        // If current element is the starting point of sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Check for next elements
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            // Update optimal length if this length is more
            ans = max(ans, j - arr[i]);
        }
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