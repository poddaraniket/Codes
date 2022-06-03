bool match(string wild, string pattern)
    {
        // code here
        int m=wild.length();
        int n=pattern.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(wild[j-1]==pattern[i-1] || wild[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(wild[j-1]=='*')
                 dp[i][j]=dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
                else
                 dp[i][j]=0;
            }
        }
        return dp[n][m];
    }