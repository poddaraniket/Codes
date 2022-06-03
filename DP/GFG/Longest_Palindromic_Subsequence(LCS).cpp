#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
     dp[i][i]=1;
    for(int gap=2;gap<=n;gap++)
     {
         for(int i=0;i<n-gap+1;i++)
          {
              int j=i+gap-1;
              if(s[i]==s[j])
               {
                   if(gap==2)
                    dp[i][j]=2;
                   else
                    dp[i][j]=dp[i+1][j-1]+2;
               }
              else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
          }
     }
    cout<<dp[0][n-1]<<endl; 
}