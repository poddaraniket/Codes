int eggDrop(int n, int k) 
    {
        // your code here
        int dp[k+1][n+1];
        for(int i=0;i<=k;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=k;i++){
            dp[i][1]=i;
        }
        for(int j=1;j<=n;j++){
            dp[1][j]=1;
        }
        for(int f=2;f<=k;f++){
            for(int e=2;e<=n;e++){
                int mini=INT_MAX;
                for(int d=1;d<=f;d++){
                    // Luck of getting broken from that floor
                    int maxi=max(dp[d-1][e-1],dp[f-d][e]);
                    //choice of picking the min from all worst scenerio
                    mini=min(mini,maxi);
                }
                dp[f][e]=mini+1;
            }
        }
        return dp[k][n];
    }