#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int i,j;     
      string a,b;
      cin>>a>>b;
      int n=a.length();
      int m=b.length();
      int dp[n+1][m+1];
      for(i=0;i<=n;i++)
       dp[i][0]=0;
      for(i=0;i<=m;i++)
       dp[0][i]=0;
      for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                 dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                 dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
       }
    //   for(i=1;i<=n;i++)
    //   {
    //       for(j=1;j<=m;j++)
    //         cout<<dp[i][j]<<" ";
    //       cout<<endl;    
    //   }
      cout<<(n+m)-dp[n][m]<<endl;
     }
}