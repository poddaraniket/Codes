#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,a,b,i;
	     string s="";
	     cin>>n>>a>>b;
	     for(i=0;i<n;i++)
	      {
	         s+=(char)('a'+(i%b)); 
	      }
	     cout<<s<<endl; 
	 }
	return 0;
}
