#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i;
	     cin>>n;
	     if(n==1)
	      cout<<"2"<<endl;
	     else
	     {
	     int dp[n+1];
	     dp[0]=0;
	     dp[1]=1;
	     for(i=2;i<=n;i++)
	      {
	          dp[i]=(dp[i-1]+(dp[i-2]+1)%1000000007)%1000000007;
	      }
	      cout<<dp[n]+1<<endl;
	     }
	 }
	return 0;
}
