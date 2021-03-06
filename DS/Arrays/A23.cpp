#include <bits/stdc++.h>
using namespace std;
//Methods
/*
    Naive Solution : Search for every possible pair
    But Expected Complexity : O(n)
*/

// Count Pairs(2 number ) that sum is equal to Given Number
int getPair(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;
    // T.C - O(n2) S.C. = O(1)

    return count;
}
// Map Based One time traversal Method
int getPairMap(int arr[], int n, int sum)
{
    // Create a Unordered Map
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(sum - arr[i]) != m.end())
        {
            count += m[sum - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}
int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = 5;
    int sum = 6;
    cout << "Count of pairs with sum " << sum << " is:" << getPairMap(arr, n, sum) << endl;

    return 0;
}