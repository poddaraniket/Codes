#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,m,k,i,j;
	   cin>>n>>m>>k;
	   int dp[n+1][m+1];
	   int a[k];
	   for(i=0;i<2*k;i++)
	    {
	        cin>>a[i];
	    }
	   //cout<<"*"<<endl; 
	   for(i=0;i<2*k;i+=2)
	    {
	        dp[a[i]][a[i+1]]=-1;
	    }
	   //cout<<"*"<<endl; 
	   for(i=0;i<=n;i++)
	     dp[i][0]=0;
	   for(i=0;i<=m;i++)
	     dp[0][i]=0;
	   dp[1][1]=1;  
	   //cout<<"*"<<endl;  
	   for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	          {
	            //dp[1][1]=1;
	            if(i==1 && j==1)
	             dp[i][j]=1;
	            else 
	             {
	              if(dp[i][j]!=-1)
	               {
	                   dp[i][j]=0;
	                   if(dp[i][j-1]!=-1)
	                     dp[i][j]=dp[i][j-1];
	                   if(dp[i-1][j]!=-1)
	                     dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000007;
	               }
	             }
	          }
	    }
	   //for(i=1;i<=n;i++)
	   // {
	   //     for(j=1;j<=m;j++)
	   //      cout<<dp[i][j]<<" ";
	   //     cout<<endl; 
	   // }
	   cout<<dp[n][m]<<endl;
	 }
	return 0;
}
