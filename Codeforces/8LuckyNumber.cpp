#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll num;
    cin>>num;
    ll luck=0,rem=0;
    while(num>0)
    {
        rem = num%10;
        if(rem==4||rem==7)
        luck++;
        num = num/10;
    }
    if(luck==4||luck==7)
    cout<<"YES";
    else 
        cout<<"NO";
    return 0;
}