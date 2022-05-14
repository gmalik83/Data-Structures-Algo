#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test_case;
    cin >> test_case;
    string str;
    while (test_case--)
    {

        cin >> str;
        int len = str.length();
        if (len > 10)
        {

            cout << str[0] << len - 2 << str[len - 1] << "\n";
        }
        else
            cout << str << "\n";
    }

    return 0;
}