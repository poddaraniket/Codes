#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int m,n,i,j;
	     cin>>m>>n;
	     int a[n];
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     int dp[n+1][m+1];
	     for(i=0;i<=m;i++)
	       dp[0][i]=1000000;
	     for(i=0;i<=n;i++)
	      dp[i][0]=0;
	     for(i=1;i<=n;i++)
	      {
	          for(j=1;j<=m;j++)
	           {
	               if(a[i-1]<=j)
	                {
	                    dp[i][j]=min(dp[i][j-a[i-1]]+1,dp[i-1][j]);
	                }
	               else
	                  dp[i][j]=dp[i-1][j];
	           }
	      }
	   //   for(i=0;i<=n;i++)
	   //    {
	   //        for(j=0;j<=m;j++)
	   //         cout<<dp[i][j]<<" ";
	   //        cout<<endl; 
	   //    }
            if(n==1 && a[0]==1)
              cout<<dp[n][m]<<endl;
            else
             {
	          if(dp[n][m]>=1000000)
	           cout<<"-1"<<endl;
	          else 
	           cout<<dp[n][m]<<endl;
	         }
	 }
	return 0;
}
