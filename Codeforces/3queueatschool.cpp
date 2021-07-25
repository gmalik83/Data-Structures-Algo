#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin>>n>>t;
    string str;
    char tmp;
    cin>>str;
    
    while (t--)
    {
        for (int i = 0; i < n-1;)
        {
            if (str[i] == 'B' && str[i + 1] == 'G')
            {
                tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
                i += 2;
            }
            else
            {
                i++;
            }
        }
    }
    cout<<str<<"\n";
    return 0;
}