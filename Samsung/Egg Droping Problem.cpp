int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++)
         dp[i][0]=0;
        for(int i=0;i<=k;i++)
         dp[0][i]=0;
        for(int i=1;i<=n;i++)
         dp[i][1]=1;
        for(int i=1;i<=k;i++) 
         dp[1][i]=i;
        for(int e=2;e<=n;e++)
         {
             for(int f=2;f<=k;f++)
              {
                  int mini=INT_MAX;
                  for(int x=1;x<=f;x++)
                   {
                       // Luck of getting broken from that floor
                       int maxi=max(dp[e-1][x-1],dp[e][f-x]);
                       //choice of picking the min from all worst scenerio 
                       mini=min(maxi,mini);
                   }
                  dp[e][f]=mini+1; 
              }
         }
        return dp[n][k]; 
    }