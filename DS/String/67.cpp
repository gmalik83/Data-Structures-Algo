#include <bits/stdc++.h>
using namespace std;
// Split Binary String into Substring with equal number of 0 1

// Function to return maximum count substring can be divided into
int maxSubStr(string str, int n)
{
    // To store count of 0 and 1's
    int count0 = 0, count1 = 0;
    // Count of Max Substring
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            count0++;
        else
            count1++;
        if (count0 == count1)
            cnt++;
    }
    // Not possible to split the string
    if (count0 != count1)
        return -1;
    return cnt;
}

// Driver Code
int main()
{
    string str = "0100110101";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}