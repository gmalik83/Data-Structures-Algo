#include <bits/stdc++.h>
using namespace std;
// Word Break Problem
/*
    Given Input String and Dictionary 
    Find if space separated exists in Dictionary

*/
// A utility function to check if a word is present in dictionary
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "like", "ice", "cream"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    // For Every element check if word is present
    for (int i = 0; i < size; i++)
    {
        if (dictionary[i].compare(word) == 0)
            return true;
    }
    // If word is not found
    return false;
}
// Utility funciton to check if string is space separated or not
bool wordBreak(string str)
{
    int size = str.size();
    // Base Case
    if (size == 0)
        return true;
    // Try all prefixes from length 1 to size
    for (int i = 1; i <= size; i++)
    {

        if (dictionaryContains(str.substr(0, i)) && wordBreak(str.substr(i, size - i)))
            return true;
    }
    // If none prefix worked
    return false;
}
int main()
{

    return 0;
}