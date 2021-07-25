#include<bits/stdc++.h>
using namespace std;

int main() {
 int n;
 cin>>n;
 string s;
 cin>>s;
 int red=0;
 int green=0;
 int blue=0;
 for(int i=1;i<n;i++){
 	if(s[i-1]==s[i])
 	if(s[i]=='R')++red;
 	else if(s[i]=='G'){
 		++green;
 	}
 	else if(s[i]=='B')
 	++blue;
 }
 cout<<red+green+blue;
  	return 0;
}