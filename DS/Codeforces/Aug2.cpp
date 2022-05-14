#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int i = 0;
        int team = 0;
        while (i < n)
        {
            if (s[i] == '1' && t[i] == '1')
            {
                team += 1;
                i++;
            }
            else if ((s[i] == '1' && t[i + 1] == '1') || (t[i] == '1' && s[i + 1] == '1'))
            {
                team += 1;
                i = i + 2;
            }

            else
                i++;
        }
        cout << team << endl;
    }
    return 0;
}
