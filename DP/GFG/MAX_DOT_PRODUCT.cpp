#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      long long int n,m,i,j;
      cin>>n>>m;
      long long int a[n],b[m];
      for(i=0;i<n;i++)
      {
       cin>>a[i];
      }
      for(i=0;i<m;i++)
      {
       cin>>b[i];
      }
      long long int dp[m+1][n+1];
      for(i=0;i<=m;i++)
       {
           for(j=0;j<=n;j++)
            dp[i][j]=0;
       }
      for(i=1;i<=m;i++)
       {
           for(j=i;j<=n;j++)
            {
                dp[i][j]=max((dp[i-1][j-1]+(a[j-1]*b[i-1])),dp[i][j-1]);
            }
       }
      cout<<dp[m][n]<<endl; 
     }
}