// nCr = n-1Cr-1 + n-1Cr

int nCr(int n, int r){
        // code here
        if(n<r)
         return 0;
        int dp[r+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=r;i++)
         dp[i][i]=1;
        for(int i=0;i<=n;i++)
         dp[0][i]=1;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j>i)
                 {
                     dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%1000000007;
                 }
            }
        }
        return dp[r][n]; 
    }