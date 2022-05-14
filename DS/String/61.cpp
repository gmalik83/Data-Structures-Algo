#include <bits/stdc++.h>
using namespace std;
#define MAX 256

/*
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
*/
// This function returns true if count of array 1 and array 2 is same
bool compare(int arr1[], int arr2[])
{
    for (int i = 0; i < MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

// This search for all permutation of pat in text
bool search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    // countP[] : store count of all character of pattern
    // countTW[] : store count of current window of text
    int countP[MAX] = {0}, countTW[MAX] = {0};
    for (int i = 0; i < M; i++)
    {
        countP[pat[i]]++;
        countTW[txt[i]]++;
    }
    // Traverse through remaining characters of pattern
    for (int i = M; i < N; i++)
    {
        if (compare(countP, countTW))
            return true;
        // Add current character to current window
        (countTW[txt[i]])++;
        // Remove first character of previous window
        countTW[txt[i - M]]--;
    }
    if (compare(countP, countTW))
        return true;
    return false;
}

int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    if (search(pat, txt))
        cout << "YES";
    else
        cout << "NO";
}