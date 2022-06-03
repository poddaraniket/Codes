double waterOverflow(int K, int R, int C) {
        // code here
        double dp[500][500];
        memset(dp,0.0,sizeof(dp));
        dp[0][0]=K;
        int glasses=0;
        for(int i=0;i<=500;i++)
         {
             bool water=false;
             glasses++;
             for(int j=0;j<glasses;j++)
              {
                if(dp[i][j]>1.0)
                 {
                     water=true;
                     double left=dp[i][j]-1;
                     dp[i][j]=1.0;
                     dp[i+1][j]+=left/2.0;
                     dp[i+1][j+1]+=left/2.0;
                 }
              }
             if(!water)
              break;
         }
        return dp[R-1][C-1]; 
    }