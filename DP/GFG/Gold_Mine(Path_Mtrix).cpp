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
       int a[n][m];
       for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
             cin>>a[i][j];
        }
       int dp[n+2][m+1];
       for(i=0;i<=m;i++)
        {
         dp[0][i]=0;
         dp[n+1][i]=0;
        }
       for(i=0;i<=n+1;i++)
        {
            dp[i][m]=0;
        }
       for(j=m-1;j>=0;j--)
        {
            for(i=1;i<=n;i++)
             {
                 dp[i][j]=a[i-1][j]+max(max(dp[i-1][j+1],dp[i][j+1]),dp[i+1][j+1]);
             }
        }
        int maxi=0;
       for(i=0;i<=n+1;i++)
        {
          maxi=max(maxi,dp[i][0]);  
        }
       cout<<maxi<<endl;    
	 }
	return 0;
}
