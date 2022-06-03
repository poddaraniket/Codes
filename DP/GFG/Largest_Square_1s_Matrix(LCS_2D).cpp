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
      int a[n][m],dp[n][m];
      for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
       }
      for(i=0;i<n;i++)
       {
           dp[i][0]=a[i][0];
       }
      for(i=0;i<m;i++)
      {
       dp[0][i]=a[0][i];
      }
      for(i=1;i<n;i++)
       {
           for(j=1;j<m;j++)
            {
                if(a[i][j]==1)
                 dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
                else
                 dp[i][j]=0;
            }
       }
      int maxi=0; 
      for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
            {
                maxi=max(maxi,dp[i][j]);
            }
       }
      cout<<maxi<<endl; 
     }
}