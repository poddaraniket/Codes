int knapSack(int W, int wt[], int val[], int n) 
    { 
       // 2D bcoz supply is finite [0/1]
       // wt/val in row as we need 1 combination[max profit] not various possibe 
       int dp[n+1][W+1];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
             {
                 if(wt[i-1]<=j)
                  dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
                 else
                  dp[i][j]=dp[i-1][j];
             }
        }
        return dp[n][W];
    }