#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d,h;
        cin>>n;
        int arr[n],pair=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<=i+1;j++)
            {
                if(i!=j)
                {
                    if(((arr[i]-arr[j])/arr[i])<(arr[i]-arr[j])/arr[j])
                    pair++;
                }
            }
        }
        cout<<pair<<endl;
        
    }
}