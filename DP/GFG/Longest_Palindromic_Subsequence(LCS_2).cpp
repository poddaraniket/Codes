#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      string s;
      cin>>s;
      int n,d,j,i;
      n=s.length();
      int dp[n][n];
      for(i=0;i<n;i++)
       {
           dp[i][i]=1;
       }
      for(d=2;d<=n;d++)
       {
           for(i=0;i<n-d+1;i++)
            {
                j=d+i-1;
                if(s[i]==s[j])
                 {
                     if(d==2)
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
}