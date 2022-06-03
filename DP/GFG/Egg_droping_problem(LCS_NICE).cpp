#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,i,j,l;
	    cin>>n>>k;
	    int dp[n+1][k+1];
	    for(i=0;i<=n;i++)
	     dp[i][0]=0;
	    for(i=0;i<=k;i++) 
	     dp[0][i]=0;
	    for(i=1;i<=k;i++)
	     dp[1][i]=i;
	    for(i=2;i<=n;i++)
	     {
	         for(j=1;j<=k;j++)
	          {
	            if(i>j)
	              dp[i][j]=dp[i-1][j];
	            else
	             {
	              int mini=10000000;      
	              for(l=1;l<=j;l++)
	               {
	                   mini=min(mini,max(dp[i-1][l-1],dp[i][j-l]));  //max(if onr egg breaks he has 1 eggless and 1 floor lessto wrk,if doesn,t he has same eggs bt k-dat floors to wrk on)
	               }
	              dp[i][j]=1+mini;    
	             }  
	          }
	     }
	   // for(i=1;i<=n;i++)
	   //  {
	   //      for(j=1;j<=k;j++)
	   //       cout<<dp[i][j]<<" ";
	   //      cout<<endl; 
	   //  }
	    cout<<dp[n][k]<<endl; 
	}
	return 0;
}
