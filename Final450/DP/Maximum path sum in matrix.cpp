int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        for(int i=0;i<N;i++)
         {
            dp[N-1][i]=Matrix[N-1][i];
         }
        for(int i=N-2;i>=0;i--)
         {
            for(int j=0;j<N;j++)
             {
                if(j==0)
                 {
                     if(j==N-1)
                      {
                          dp[i][j]=Matrix[i][j]+dp[i+1][j];
                      }
                     else
                      {
                          dp[i][j]=Matrix[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
                      }
                 }
                else if(j==N-1)
                 {
                     dp[i][j]=Matrix[i][j]+max(dp[i+1][j],dp[i+1][j-1]);
                 }
                else
                 {
                     dp[i][j]=Matrix[i][j]+max(dp[i+1][j+1],max(dp[i+1][j],dp[i+1][j-1]));
                 }
             }
         }
        int maxi=0; 
        for(int i=0;i<N;i++)
         {
            maxi=max(dp[0][i],maxi);
         }
        return maxi; 
    }