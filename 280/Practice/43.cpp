#include <bits/stdc++.h>
using namespace std;
// Find Length of Smallest Window That Contains all the Characters
string MinimumWindow(string s, string t)
{
    int m[256] = {0};
    // Answer
    int ans = INT_MAX;
    int start = 0;
    int count = 0;
    // Creating Map
    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }
    int i = 0, j = 0;
    // Traverse the Window
    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "-->Smallest window that contain all character : " << endl;
    cout << MinimumWindow(s, t);
    return 0;
}
