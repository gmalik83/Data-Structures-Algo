#include <bits/stdc++.h>
using namespace std;

// Minimum steps to make balance bracket

// Function calculate to minimum swaps
int swapCount(string s)
{
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
            pos.push_back(i);
    }
    int count = 0; // Count Number of '['
    int p = 0;     // For next position of [
    long sum = 0;  // to store result
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;
        // Unbalanced part of string
        if (count < 0)
        {
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;

            count = 1;
        }
    }
    return sum;
}

int main()
{
    string s = "[]][][";
    cout << swapCount(s) << "\n";

    s = "[[][]]";
    cout << swapCount(s) << "\n";

    return 0;
}