int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        //dp[0][0]=1
        int result=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
              {
                  if(S1[i-1]==S2[j-1])
                  {
                    dp[i][j]=dp[i-1][j-1]+1;
                    result=max(result,dp[i][j]);
                  }
                  else
                   dp[i][j]=0;
              }
         }
        return result; 
    }