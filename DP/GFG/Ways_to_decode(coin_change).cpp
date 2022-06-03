#include <bits/stdc++.h>
using namespace std;

int decode(string s,int n)
 {
     int dp[n+1],i;
     dp[0]=1;
     if(s[0]=='0')
        return 0;
     dp[1]=1;
     for(i=2;i<=n;i++)
      {
          int c1=0,c2=0;
          if(s[i-1]>'0')
           c1=dp[i-1];
          if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<'7')
           c2=dp[i-2];
          dp[i]=c1+c2; 
      }
     return dp[n]; 
 }

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	 {
	     int n;
	     cin>>n;
	     int dp[n+1];
	     string s;
	     cin>>s;
	     cout<<decode(s,n)<<endl;;
	 }
	return 0;
}