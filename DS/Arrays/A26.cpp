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
    int minEle = INT_MAX;
    // Find Minimum Element in array
    for (int i = 0; i < n; i++)
        minEle = min(arr[i], minEle);
    // Initialize current sum
    int curr_sum = arr[0] + abs(minEle), start = 0, i;
    int targetSum = sum;
    // Add one by one and if it exceeds remove first one
    for (int i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum - (i - start) * abs(minEle) > targetSum && start < i)
        {
            curr_sum = curr_sum - arr[start] - abs(minEle);
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum - (i - start) * abs(minEle) == targetSum)
        {
            cout << "Sum found between indexes " << start << " and " << i - 1;
            return;
        }

        // Add this element to curr_sum
        if (i < n)
        {
            curr_sum = curr_sum + arr[i] + abs(minEle);
        }
    }
    // Reached end of array
    cout << "No subarray found " << endl;
}
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = 8;
    int sum = 6;
    subarraySum(arr, n, sum);

    return 0;
}