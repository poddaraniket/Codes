#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int n,d,i,j,k;
      cin>>n;
      int a[n];
      for(i=0;i<n;i++)
       cin>>a[i];
      long long int dp[n][n];
      for(i=1;i<n;i++)
       dp[i][i]=0;
      for(d=1;d<n-1;d++)
      {
      for(i=1;i<n-d;i++)
       {
           int j=i+d;
           dp[i][j]=100000000000000;
           for(k=i;k<j;k++)
            dp[i][j]=min(dp[i][k]+dp[k+1][j]+(a[i-1]*a[k]*a[j]),dp[i][j]);
       }
      }
     cout<<dp[1][n-1]<<endl; 
     }
}