int knapSack(int N, int W, int val[], int wt[])
    {
        // 1D as supply is infite
        // we need 1 combination(max profit) so take wt/val as ROW
        int dp[W+1]={0};
        for(int i=0;i<N;i++)
        {
          for(int j=1;j<=W;j++)
            {
                if(wt[i]<=j){
                    dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
                }
            }  
        }
        return dp[W];
    }