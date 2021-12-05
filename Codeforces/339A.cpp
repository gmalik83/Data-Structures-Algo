#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1001];
    string str;
    cin >> str;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+')
        {
            continue;
        }
        else
        {
            arr[count++] = str[i] - '0';
        }
    }
    sort(arr, arr + count);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i];
        if (i == count - 1)
        {
            break;
        }
        cout << "+";
    }
    return 0;
}