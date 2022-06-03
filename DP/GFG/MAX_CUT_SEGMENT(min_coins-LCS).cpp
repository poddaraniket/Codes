#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i,a[3],j;
	     cin>>n;
	     cin>>a[0]>>a[1]>>a[2];
	     int dp[n+1]={0};
	     for(i=0;i<3;i++)
	      {
	          for(j=1;j<=n;j++)
	           {
	               if(j==a[i])
	                 dp[j]=max(dp[j-a[i]]+1,dp[j]);
	               if(j>a[i])
	                 {
	                     if(dp[j-a[i]]!=0)
	                       dp[j]=max(dp[j-a[i]]+1,dp[j]);
	                 }
	           }
	      }
	     cout<<dp[n]<<endl; 
	 }
	return 0;
}
