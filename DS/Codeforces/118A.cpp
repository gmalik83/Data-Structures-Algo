#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string ans;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'A' || str[i] == 'O' || str[i] == 'I' || str[i] == 'E' || str[i] == 'U' || str[i] == 'Y' || str[i] == 'a' || str[i] == 'o' || str[i] == 'i' || str[i] == 'e' || str[i] == 'u' || str[i] == 'y')
        {
            continue;
        }
        else
        {
            ans.push_back('.');
            ans.push_back(tolower(str[i]));
        }
    }
    cout << ans << "\n";

    return 0;
}