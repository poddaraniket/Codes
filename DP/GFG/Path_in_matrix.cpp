#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,i,j;
	    cin>>n;
	    int t[n][n];
	    for(i=0;i<n;i++)
	     {
	         for(j=0;j<n;j++)
	          cin>>t[i][j];
	     }
	    int dp[n][n+2];
	    for(i=0;i<n;i++)
	     {
	      dp[i][0]=0;
	      dp[i][n+1]=0;
	     }
	    for(i=1;i<=n;i++)
	      dp[n-1][i]=t[n-1][i-1];
	    for(i=n-2;i>=0;i--)
	     {
	         for(j=1;j<=n;j++)
	           {
	               dp[i][j]=t[i][j-1]+max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
	           }
	     }
	    int maxi=0; 
	   for(i=1;i<=n;i++)
	    {
	       maxi=max(dp[0][i],maxi); 
	    }
	   // for(i=0;i<n;i++)
	   //  {
	   //      for(j=0;j<=n+1;j++)
	   //       cout<<dp[i][j]<<" ";
	   //      cout<<endl; 
	   //  }
	    cout<<maxi<<endl; 
	 }
	return 0;
}
