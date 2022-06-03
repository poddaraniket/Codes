int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[N+1][W+1];
        for(int i=0;i<=N;i++)
         {
            for(int j=0;j<=W;j++){
                dp[i][j]=100000000;
            } 
         }
        for(int i=0;i<=N;i++)
         dp[i][0]=0;
        for(int i=1;i<=N;i++)
         {
            for(int j=1;j<=W;j++)
             {
                if(j>=i && cost[i-1]!=-1)
                 {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-i]+cost[i-1],dp[i-1][j-i]+cost[i-1])); 
                 }
                else 
                    dp[i][j]=dp[i-1][j];
             }
         }
        // for(int i=1;i<=N;i++){
        //     for(int j=1;j<=W;j++)
        //      {
        //          cout<<dp[i][j]<<" ";
        //      }
        //     cout<<endl; 
        // }
        return dp[N][W]==100000000?-1:dp[N][W];
	} 