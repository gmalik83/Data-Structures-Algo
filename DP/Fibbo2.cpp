#include <bits/stdc++.h>
using namespace std;

// Simple Recursion and Use DP array from
// Or can use 2 variables a b c c= a+b; a = b ; b = c;

int fibbonacci(int n)
{
    int f[n + 2];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

int main()
{

    int n = 5;
    cout << fibbonacci(n) << endl;
    return 0;
}