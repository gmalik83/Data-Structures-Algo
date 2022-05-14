#include <bits/stdc++.h>
using namespace std;

#define MAX 26

// Function to return Lexicographically String After Swapping Occurences
string smallestStr(string str, int n)
{
    int i, j;
    // To Store First Index of Every Character
    int chk[MAX];
    for (int i = 0; i < MAX; i++)
    {
        chk[i] = -1;
    }
    // Store the first Occuring Index for every Character
    for (int i = 0; i < n; i++)
    {
        // If Current Character is Appearing for First Time
        if (chk[str[i] - 'a'] == -1)
        {
            chk[str[i] - 'a'] = i;
        }
    }

    // Start from LeftMost Character
    for (i = 0; i < n; i++)
    {
        bool flag = false;
        // For Every Character Smaller than str[i]
        for (j = 0; j < str[i] - 'a'; j++)
        {
            if (chk[j] > chk[str[i] - 'a'])
            {
                flag = true;
                break;
            }
        }
        // If Pair is Found
        if (flag)
            break;
    }
    // If Swapping is Possible
    if (i < n)
    {
        char ch1 = str[i];
        char ch2 = char(j + 'a');
        // For Every Character
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch1)
                str[i] = ch2;
            else if (str[i] == ch2)
                str[i] = ch1;
        }
    }
    return str;
}

// Driver Code
int main()
{
    string str = "ccad";
    int n = str.length();

    cout << smallestStr(str, n)<<endl;

    return 0;
}