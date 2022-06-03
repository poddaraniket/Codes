#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes 
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j,maxi=0;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	   // temp=min(n,m);
	    int dp[n+1][m+1];
	    for(i=0;i<=n;i++)
	     dp[i][0]=0;
	    for(i=0;i<=m;i++)
	     dp[0][i]=0;
	    dp[0][0]=0;
	    for(i=1;i<=n;i++)
	     {
	         for(j=1;j<=m;j++)
	          {
	             if(a[i-1]==b[j-1])
	              dp[i][j]=dp[i-1][j-1]+1;
	             else
	              dp[i][j]=0;
	             maxi=max(maxi,dp[i][j]); 
	          }
	     }
	    cout<<maxi<<endl; 
	}
	return 0;
}
