int editDistance(string s, string t) {
        // Code here
        int m=s.length();
        int n=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                                    //Insert       //Remove   //Replace
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        return dp[n][m];
    }