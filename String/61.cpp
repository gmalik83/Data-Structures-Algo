#include <bits/stdc++.h>
using namespace std;

// Function to check if string A is shuffled substring of B or not

bool isShuffledSubstring(string A, string B)
{
    int n = A.length();
    int m = B.length();
    if (n > m)
        return false;
    else
    {
        // Sort String A
        sort(A.begin(), A.end());
        // Traverse String B
        for (int i = 0; i < m; i++)
        {
            // if(i+n-1>=m) does not satisfy
            if (i + n - 1 >= m)
                return false;
            // Initialize new String
            string str = "";
            // Copy the characters of string B in str till length n
            for (int j = 0; j < n; j++)
                str.push_back(B[i + j]);
            // Sort the string str
            sort(str.begin(), str.end());
            if (str == A)
                return true;
        }
    }
    return false;
}
// Driver Code
int main()
{
    // Input str1 and str2
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";

    // Function return true if
    // str1 is shuffled substring
    // of str2
    bool a = isShuffledSubstring(str1, str2);

    // If str1 is substring of str2
    // print "YES" else print "NO"
    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}