int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
         {
             for(int j=1;j<=W;j++)
               {
                   if(j>=wt[i])
                    dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
               }
         }
        return dp[W]; 
    }