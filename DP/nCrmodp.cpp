#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r, int p)
{
    if (r > n - r)
        r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    return C[r];
}

int main()
{
    int n = 5, r = 2, p = 1000007;
    cout << "Value of nCr % p " << solve(n, r, p);
    return 0;
}