#include <bits/stdc++.h>
using namespace std;

/*const int no_of_chars = 256;
// find-the-smallest-window-in-a-string-containing-all-characters-of-another-string

// Function to find smallest window containing all character of pattern
string findSubString(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();
    // If string lenght is less than pat length , no string exist
    if (len1 < len2)
    {
        cout << "No such window exists\n";
        return "";
    }

    int hash_pat[no_of_chars] = {0};
    int hash_str[no_of_chars] = {0};
    // Store occurance of characters
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX;
    // Start traversing the string count of characters
    int count = 0;
    for (int j = 0; j < len1; j++)
    {
        // Count occurence of character in string
        hash_str[str[j]]++;
        // if string char matches with pat char then increment count
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;
        // If all character is matched
        if (count == len2)
        {
            // Try to minimize the window
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
            {
                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
            // Update the window size
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    // If no window is found
    if (start_index == -1)
    {
        cout << "No such window exists\n";
        return "";
    }
    // Return substring starting from start_index and length min_len
    return str.substr(start_index, min_len);
}

int main()
{
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : \n"
         << findSubString(str, pat);
    return 0;
}
*/
