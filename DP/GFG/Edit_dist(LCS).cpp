#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i,j,m;
	     cin>>n>>m;
	     int dp[n+1][m+1];
	     char a[n],b[m];
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     for(i=0;i<m;i++) 
	      cin>>b[i];
	     for(i=0;i<=m;i++)
	      dp[0][i]=i;
	     for(i=0;i<=n;i++)
	      dp[i][0]=i;
	     for(i=1;i<=n;i++)
	      {
	          for(j=1;j<=m;j++)
	           {
	               if(a[i-1]==b[j-1])
	                {
	                    dp[i][j]=dp[i-1][j-1];
	                }
	               else
	                 dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
	           }
	      }
	   //  for(i=1;i<=n;i++)
	   //   {
	   //       for(j=1;j<=m;j++)
	   //        cout<<dp[i][j]<<" ";
	   //    cout<<endl;
	   //   }
	     cout<<dp[n][m]<<endl; 
	 }
	return 0;
}
