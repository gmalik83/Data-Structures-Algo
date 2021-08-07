#include <bits/stdc++.h>
using namespace std;
// Maximum Continuous subarray Sum
vector<int> maxSubArraySum(int a[], int size)
{
    vector<int> v;
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is: "
         << max_so_far << endl;
    v.push_back(start);
    v.push_back(end);
    return v;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;
    vector<int> v = maxSubArraySum(a, n);
    cout << "Maximum Subarray is:";
    for (int i = v[0]; i <= v[1]; i++)
        cout << a[i] << " ";
    return 0;
}
