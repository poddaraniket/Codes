#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,m,i,j;
	     cin>>n>>m;
	     char a[n],b[m]; 
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     for(i=0;i<m;i++)
	      cin>>b[i];
	     int dp[n+1][m+1]; 
	     for(i=0;i<=n;i++)
	      {
	         dp[i][0]=0; 
	      }
	     for(i=0;i<=m;i++)
	      dp[0][i]=0;
	     for(i=1;i<=n;i++)
	      {
	          for(j=1;j<=m;j++)
	           {
	               if(a[i-1]==b[j-1])
	                {
	                    dp[i][j]=dp[i-1][j-1]+1;  //prints 1 plus to the value we got comparing(a[]) till previous string to the one being to compared to (b[]) b4 that char.
	                }
	               else
	                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	           }
	      }
	     cout<<dp[n][m]<<endl;
	 }
	return 0;
}
