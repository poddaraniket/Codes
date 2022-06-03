#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int n,m,i,j;
      cin>>n>>m;
      int dp[n][m];
      for(i=0;i<m;i++)
       dp[0][i]=1;
      for(i=0;i<n;i++)
       dp[i][0]=1;
      for(i=1;i<n;i++)
       {
           for(j=1;j<m;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
       }
      cout<<dp[n-1][m-1]<<endl; 
     }
}