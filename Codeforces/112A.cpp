#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    int l1 = a.length();
    int total1 = 0, total2 = 0;
    for (int i = 0; i < l1; i++)
    {
        total1 += a[i];
        total2 += b[i];
    }
    if (total1 == total2)
        cout << 0 << endl;
    else if (total1 < total2)
        cout << -1 << endl;
    else
        cout << 1 << endl;

    return 0;
}