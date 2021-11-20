#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll findMax(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll maxVal = findMax(a, b, c);
        ll a1, b1, c1;
        if (a == b && a == c)
        {
            a1 = a + 1;
            b1 = b + 1;
            c1 = c + 1;
        }
        else
        {
            if (a == maxVal)
            {
                a1 = 0;
                b1 = maxVal - b + 1;
                c1 = maxVal - c + 1;
            }
            else if (b == maxVal)
            {
                b1 = 0;
                a1 = maxVal - a + 1;
                c1 = maxVal - c + 1;
            }
            else if (c == maxVal)
            {
                c1 = 0;
                a1 = maxVal - a + 1;
                b1 = maxVal - b + 1;
            }
        }
        cout << a1 << " " << b1 << " " << c1 << "\n";
    }
    return 0;
}