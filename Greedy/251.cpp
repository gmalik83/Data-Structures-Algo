#include<bits/stdc++.h>
using namespace std;
// Find Maximum Number of Meetings in One Room
void maxMeetings(int s[],int f[],int n)
{
    pair<int,int> a[n+1];
    int i;
    for( i=0;i<n;i++)
    {
        a[i].first = f[i];
        a[i].second = i;
    }
    // Sort Meeting According to their Finish Time 
    sort(a,a+n);
    // Time Limit 
    int time_limit = a[0].first;

    // Selected Meetings 
    vector<int> m;
    // Select the First Meeting 
    m.push_back(a[0].second+1);
    // Check For All Meeting Whether it Can be Selected or not
    for(i=1;i<n;i++){
        if(s[a[i].second]>time_limit){
            // Push Selected Meeting to Vector
            m.push_back(a[i].second+1);

            // Update Time Limit
            time_limit = a[i].first;

        }
    }
    for(i=0;i<m.size();i++)
    {
        cout<<m[i]<<" ";
    }
}

int main()
{

    // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
 
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
 
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeetings(s, f, n);
 
    return 0;
}