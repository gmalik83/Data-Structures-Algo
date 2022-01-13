#include <bits/stdc++.h>
using namespace std;
/*
    Find Subarray With Sum 0
    1.Naive Method : Check For All Subarrays with sum 0
    2. Use Prefix Sum Hashmap 
       For Every Index : 
        2.1 if (curr_sum == given_sum) true and print from 0 to i
        2.2 if(mp.find(curr_sum-mp[i])) print that subarray
*/
void subarraySum(int arr[], int n, int sum)
{
    // Time Complexity : O(n) Space Complexity : O(n) as hashmap takes space
    // Create an empty map
    unordered_map<int, int> map;
    // Maintain Sum of Element so far
    int curr_sum = 0;

    // Loop for every element
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        // If current sum is equal to target sum
        // Then Subarray is found
        if (curr_sum == sum)
        {
            cout << "Sum found between indexes " << 0 << " to " << i << endl;
            return;
        }
        // If curr_sum- sum exist then found subarray with target sum
        if (map.find(curr_sum - sum) != map.end())
        {
            cout << "Sum found between indexes " << map[curr_sum - sum] + 1 << " to " << i << endl;
            return;
        }
        map[curr_sum] = i;
    }
    // If we reach here , then no subarray exists
    cout << "No subarray with " << sum << " sum exists" << endl;
}
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = 8;
    int sum = 116;
    subarraySum(arr, n, sum);

    return 0;
}