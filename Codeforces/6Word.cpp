#include<bits/stdc++.h>
using namespace std;
int main()
{
    int countLower = 0,countUpper=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            countUpper++;
        else if(s[i]>='a'&&s[i]<='z')
            countLower++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(countUpper>countLower)
        {
             if(s[i]>='a'&&s[i]<='z')
                s[i] = s[i]-32;

        }
        else {
            if(s[i]>='A'&&s[i]<='Z')
            s[i] = s[i]+32;
        }
    }
    cout<<s<<endl;

}