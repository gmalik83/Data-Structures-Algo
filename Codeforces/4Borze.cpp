#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,str2;
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='.')
        str2+='0';
        else if(str[i]=='-'&&str[i+1]=='.')
        {
            str2+='1';
            ++i;
        }
        else if(str[i]=='-'&&str[i+1]=='-')
        {
            str2+='2';
            ++i;
        }
    }
    cout<<str2<<endl;
    return 0;
}