int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int dp[n][n];
        memset(dp,1000000,sizeof(dp));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(gap==0 || gap==1)
                    dp[i][j]=0;
                else if(gap==2)
                    dp[i][j]=values[i]*values[i+1]*values[i+2];
                else{
                   for(int k=i+1;k<j;k++)
                    {
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
                    } 
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                 cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[0][n-1];
        
    }