#include<bits/stdc++.h>

using namespace std;

int main()
{
    string src,tar;
    cin>>src>>tar;
    int m=src.length();
    int n=tar.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
     {
        dp[i][m]=0; 
     }
    for(int j=0;j<=m;j++)
     {
        dp[n][j]=1; 
     }
    for(int i=n-1;i>=0;i--)
     {
        for(int j=m-1;j>=0;j--) 
         {
            if(src[j]!=tar[i])
             dp[i][j]=dp[i][j+1];
            else
             dp[i][j]=dp[i][j+1]+dp[i+1][j+1];
            cout<<dp[i][j]<<" "; 
         }
        cout<<endl; 
     }
    return dp[0][0]; 
}