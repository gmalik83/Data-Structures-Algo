#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int res = a+b+c;

        if(a<=b && a<=c)
        res -= a;
        else if(b<=a && b<=c)
        res -= b;
        else res -=c;
        cout<<res<<endl;
        
    }
}