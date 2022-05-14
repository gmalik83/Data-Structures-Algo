#include <bits/stdc++.h>
using namespace std;

// Function to Find Minimum Days
void survival(int S, int N, int M)
{
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        cout << "We Cannot Survive";
    else
    {
        int days = (M * S) / N;
        if (((M * S) % N) != 0)
            days++;
        cout << "Yes " << days << endl;
    }
}

int main()
{
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
    return 0;
}