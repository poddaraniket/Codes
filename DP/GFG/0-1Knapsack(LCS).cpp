#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,cap,i,j;
	     cin>>n>>cap;
	     int val[n],wt[n],dp[n+1][cap+1];
	     for(i=0;i<n;i++)
	      cin>>val[i];
	     for(i=0;i<n;i++)
	      cin>>wt[i];
	     for(i=0;i<=n;i++)
	      dp[i][0]=0;
	     for(i=0;i<=cap;i++)
	      dp[0][i]=0;
	     for(i=1;i<=n;i++)
	      {
	          for(j=1;j<=cap;j++)
	           {
	               if(j<wt[i-1])
	                 dp[i][j]=dp[i-1][j];
	               else 
	                 dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	           }
	      }
	   //  for(i=1;i<=n;i++)
	   //   {
	   //       for(j=1;j<=cap;j++)
	   //         cout<<dp[i][j]<<" ";
	   //      cout<<endl;     
	   //   }
	     cout<<dp[n][cap]<<endl; 
	 }
	return 0;
}
