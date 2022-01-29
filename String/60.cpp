#include <bits/stdc++.h>
using namespace std;

// Function to check if strings are rotations of each other
bool isRotations(string str1, string str2)
{
    // Check if size is same
    if (str1.length() != str2.length())
        return false;
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";
    if (isRotations(str1, str2))
        cout << "Strings are Rotations of Each Other.\n";
    else
        cout << "Strings are Not Rotations of Each Other.\n";

    return 0;
}