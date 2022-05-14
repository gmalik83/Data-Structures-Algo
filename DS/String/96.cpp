#include <bits/stdc++.h>
using namespace std;

// Transform String A to String B using minimum number of operations
int minOps(string &A, string &B)
{
    int m = A.length(), n = B.length();
    // If length is not same then Conversion is not possible
    if (m != n)
        return -1;
    // Map for value
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++)
        // Count characters in B
        count[B[i]]++;
    for (int i = 0; i < n; i++)
        count[A[i]]--; // Subtract count for every character in A
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;)
    {
        while (i >= 0 && A[i] != B[i])
        {
            i--;
            res++;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}

int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is "
         << minOps(A, B);

    return 0;
}