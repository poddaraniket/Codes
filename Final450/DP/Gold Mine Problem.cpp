int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n][m];
        for(int i=0;i<n;i++){
            dp[i][m-1]=M[i][m-1];
        }
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                if(i==0){
                    if(i==n-1)
                     dp[i][j]=M[i][j]+dp[i][j+1];
                    else 
                     dp[i][j]=M[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
                }
                else if(i==n-1)
                 dp[i][j]=M[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
                else 
                 dp[i][j]=M[i][j]+max(max(dp[i][j+1],dp[i-1][j+1]),dp[i+1][j+1]);
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
         {
            maxi=max(maxi,dp[i][0]); 
         }
        return maxi; 
    }