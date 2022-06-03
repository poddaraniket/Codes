#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,m;
    cin>>m>>n;
    int dp[m][n+1];
    for(int i=0;i<=n;i++)
     dp[0][i]=i;
    for(int i=0;i<m;i++)
     dp[i][0]=0;
    int sum=dp[0][n]; 
    for(int i=1;i<m;i++)
     {
        for(int j=1;j<=n;j++)
         {
            if(j*2<=n) 
             dp[i][j]=dp[i][j-1]+(sum-dp[i-1][(j*2)-1]);
            else
             dp[i][j]=dp[i][j-1];
         }
        sum=dp[i][n]; 
     }
    // for(int i=0;i<m;i++)
    //  {
    //      for(int j=0;j<=n;j++)
    //       cout<<dp[i][j]<<" ";
    //      cout<<endl; 
    //  }
    cout<<dp[m-1][n]<<endl; 
}